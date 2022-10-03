#pragma once

#include <string>

class Animal {
 public:
  Animal() : id_(0), name_(""), type_("") {}
  Animal(int id, std::string name, std::string type)
      : id_(id), name_(name), type_(type) {}

  virtual std::string bark() = 0;

  int id_;
  std::string name_;
  std::string type_;
};