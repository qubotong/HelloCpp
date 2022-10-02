#include "animal/dog.h"

#include <gtest/gtest.h>

#include "animal/animal.pb.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.

  proto::Animal animal_proto;
  animal_proto.set_name("jack");
  animal_proto.set_id(12);
  animal_proto.set_type("dog");

  Dog dog(animal_proto);
  ASSERT_EQ(dog.id_, 12);
}