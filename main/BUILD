cc_binary(
    name = "hello",
    srcs = ["hello.cpp"],
    deps = [
        "//animal:animal_cc_proto",
        "//animal:dog",
        "@com_github_gflags_gflags//:gflags",
        "@com_github_google_glog//:glog",
    ],
)

py_binary(
    name = "vis",
    srcs = ["vis.py"],
)
