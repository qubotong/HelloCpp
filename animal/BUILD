load("@rules_proto//proto:defs.bzl", "proto_library")
load("@com_google_protobuf//:protobuf.bzl", "py_proto_library")

cc_proto_library(
    name = "animal_cc_proto",
    visibility = ["//visibility:public"],
    deps = [":animal_proto"],
)

py_proto_library(
    name = "animal_py_proto",
    srcs = [":animal.proto"],
)

proto_library(
    name = "animal_proto",
    srcs = [
        "animal.proto",
    ],
)

cc_library(
    name = "dog",
    srcs = [
    ],
    hdrs = [
        "animal.h",
        "dog.h",
        ":animal_cc_proto",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "dog_test",
    size = "small",
    srcs = ["dog_test.cpp"],
    deps = [
        ":animal_cc_proto",
        ":dog",
        "@com_google_googletest//:gtest_main",
    ],
)
