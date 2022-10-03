def sum(n):
    s = 0
    for i in range(0, n):
        s += i
    print(s)
    return s

def copy_file(name, src, **kwargs):
    """creat a new file
    """

    #index = sum(20)
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
