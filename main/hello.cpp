#include <gflags/gflags.h>
#include <glog/logging.h>

#include <Eigen/Dense>
#include <iostream>

#include "animal/animal.pb.h"
#include "animal/dog.h"

using Eigen::MatrixXd;

DEFINE_bool(a, true, "test gflag lib");

void printMatrix() {
  MatrixXd m(2, 2);
  m(0, 0) = 3;
  m(1, 0) = 2.5;
  m(0, 1) = -1;
  m(1, 1) = m(1, 0) + m(0, 1);
  std::cout << m << std::endl;
}

int main(int argc, char *argv[]) {
  FLAGS_log_dir = "./main/";
  // Initialize Google’s logging library.
  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = 1;

  gflags::ParseCommandLineFlags(&argc, &argv, true);

  LOG(INFO) << "Found cookies!!!";
  // brun main:hello -- --noa
  LOG(INFO) << "set the flag: Flag_a:" << FLAGS_a;

  proto::Animal dog_proto;
  dog_proto.set_name("Jack");

  Dog my_dog(dog_proto);

  std::cout << "name:" << dog_proto.name() << std::endl;
  std::cout << my_dog.bark() << std::endl;

  printMatrix();
}