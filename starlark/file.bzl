def sum(n):
    s = 0
    for i in range(0, n):
        s += i
    print(s)
    return s

def copy_file(name, src, **kwargs):
    native.genrule(
        name = name + "_copy1",
        srcs = [src],
        outs = ["data_cp1.txt"],
        cmd = "cp $< $@",
        **kwargs
    )

    native.genrule(
        name = name + "_copy2",
        srcs = [src],
        outs = ["data_cp2.txt"],
        cmd = "cp $< $@",
        **kwargs
    )

    native.genrule(
        name = name,
        srcs = [
            "data_cp1.txt",
            "data_cp2.txt",
        ],
        outs = ["data_new.txt"],
        cmd = "cat $(SRCS) > $@",
        **kwargs
    )

def _create_file_impl(ctx):
    out_file = ctx.actions.declare_file("%s.txt" % ctx.attr.name)
    out_file_pwd = ctx.actions.declare_file("%s_pwd.txt" % ctx.attr.name)

    content_str = ctx.attr.txt
    out_file_path = out_file.path
    print(out_file_path)
    print(content_str)

    # Action is run at the execroot dir, which is /home/bqu/.cache/bazel/_bazel_bqu/a301191490f382ad071d334d1153e67d/sandbox/linux-sandbox/73/execroot/HELLOCPP
    ctx.actions.run(
        outputs = [out_file],
        arguments = [out_file_path, content_str],
        progress_message = "writing a string \"{}\" to file \"{}\"".format(content_str, out_file_path),
        executable = ctx.executable._bin,
    )

    ctx.actions.run_shell(
        progress_message = "output PWD",
        # outputs = [out_file], #??? not sure whether two actions can write to the same file
        outputs = [out_file_pwd],
        inputs = [out_file],  #without this input, the build fails since missing the input file
        arguments = [out_file_pwd.path],
        # command = "echo $PWD | cat - %s >> $1" % out_file_path,
        command = "echo $PWD | cat - {} >> $1".format(out_file_path),
    )

    return [DefaultInfo(files = depset([out_file, out_file_pwd]))]

create_file = rule(
    implementation = _create_file_impl,
    attrs = {
        "txt": attr.string(
            default = "This is a default text@@@",
            mandatory = True,
            doc = "The content to be write",
        ),
        "_bin": attr.label(
            executable = True,
            cfg = "exec",
            allow_files = True,
            default = Label("//starlark:read_write"),
        ),
    },
    doc = "create a file with time stamp and some txt.",
)
