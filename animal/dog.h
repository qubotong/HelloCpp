#pragma once

#include <string>

#include "animal/animal.h"
#include "animal/animal.pb.h"

class Dog : public Animal {
 public:
  Dog() { type_ = "Dog"; };
  // base variable cannot be accessed through initializer list, but can be
  // accessed through constructor
  Dog(const proto::Animal &animal_proto)
      : Animal(animal_proto.id(), animal_proto.name(), animal_proto.type()) {}
  ~Dog(){};

  std::string bark() override {
    return type_ + "(" + name_ + ")(" + std::to_string(id_) +
           ") barks wang wang wang...";
  }
};
