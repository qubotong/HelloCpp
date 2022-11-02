#include <iostream>

bool getFalse(){
  return false;
}

bool getTrue(){
  return true;
}

int getValue(int value){
  return value*10;
}


void learn_variable_assignment_in_if_statement(){
  //we can assign the variable inside the if statement
  if(auto a = getValue(10)){
    std::cout << a << std::endl;
  }
  //however, there is no way to nest assignment with other statement
  //error: expected primary-expression before 'auto'
  // if(getTrue() && (auto a = getValue(10))){
  //   std::cout << a << std::endl;
  // }

  //the following works
  int a;
  if(getTrue() && (a = getValue(10))){
    std::cout << a << std::endl;
  }
}

int main(int argc, char *argv[]) {

  learn_variable_assignment_in_if_statement();

  return 0;
}