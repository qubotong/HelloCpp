load("@rules_proto//proto:defs.bzl", "proto_library")
load("@com_google_protobuf//:protobuf.bzl", "py_proto_library")

cc_binary(
    name = "hello",
    srcs = ["hello.cpp"],
    deps = [
        ":addressbook_cc_proto",
        "@com_github_gflags_gflags//:gflags",
        "@com_github_google_glog//:glog",
    ],
)

cc_proto_library(
    name = "addressbook_cc_proto",
    deps = [":addressbook_proto"],
)

py_proto_library(
    name = "addressbook_py_proto",
    srcs = [":addressbook.proto"],
)

proto_library(
    name = "addressbook_proto",
    srcs = [
        "addressbook.proto",
    ],
)

py_binary(
    name = "vis",
    srcs = ["vis.py"],
)

cc_test(
    name = "hello_test",
    size = "small",
    srcs = ["hello_test.cpp"],
    deps = ["@com_google_googletest//:gtest_main"],
)
