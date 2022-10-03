load("//starlark:copy.bzl", "copy_file")

copy_file(
    name = "new_file",
    src = "data.txt",
)

cc_binary(
    name = "read_write",
    srcs = ["read_write.cpp"],
    data = [
        ":new_file",
    ],
)
