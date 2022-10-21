def _get_pwd_impl(ctx):
    out_file = ctx.actions.declare_file("%s_pwd.txt" % ctx.attr.name)

    ctx.actions.run_shell(
        progress_message = "save PWD",
        outputs = [out_file],
        arguments = [out_file.path],
        command = "echo $PWD >> $1",
    )

    return [DefaultInfo(files = depset([out_file]))]

get_pwd = rule(
    implementation = _get_pwd_impl,
    doc = "create a file with current pwd.",
)
