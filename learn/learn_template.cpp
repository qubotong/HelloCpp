#include <iostream>
#include <typeinfo>

template <typename T>
inline const char* typeName() {
  return typeid(T).name();
};

template<typename Type>
class Foo{
  public: 

  void print(){
    std::cout << "type of the Foo is:" << typeName<Type>() << std::endl;
    std::cout << "type of the Foo is:" << typeid(Type).name() << std::endl;
    //typeName is not a std function. It uses typeid function
  }

};

int main(int argc, char *argv[]) {
  std::cout << "hello world " << std::endl;
  Foo<int> test_case;
  test_case.print();

  const char*str = "test string";
  std::cout << str << std::endl;

  return 0;
}