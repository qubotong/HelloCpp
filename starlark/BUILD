load("//starlark:file.bzl", "copy_file", "create_file")
load("//starlark:get_pwd.bzl", "get_pwd")

copy_file(
    name = "new_file",
    src = "data.txt",
)

cc_binary(
    name = "read_write",
    srcs = ["read_write.cpp"],
)

create_file(
    name = "test_file",
    txt = "hello this test!!!",
)

get_pwd(
    name = "test_get_pwd",
)
