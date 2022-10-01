#include <iostream>

#include <glog/logging.h>
#include <gflags/gflags.h>

#include "main/addressbook.pb.h"

DEFINE_bool(a, true, "test gflag lib");

int main(int argc, char *argv[])
{
    FLAGS_log_dir = "./main/";
    // Initialize Google’s logging library.
    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = 1;

    gflags::ParseCommandLineFlags(&argc, &argv, true);

    LOG(INFO) << "Found cookies!!!";
    // brun main:hello -- --noa
    LOG(INFO) << "set the flag: Flag_a:" << FLAGS_a;

    proto::Person person;
    person.set_name("qubotong");

    std::cout << "name:" << person.name() << std::endl;
    std::cout << "hello world!" << std::endl;
}