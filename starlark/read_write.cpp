#include <fstream>
#include <iostream>
#include <string>

int writeFile(const std::string& file_name) {
  std::ofstream myfile(file_name);
  if (myfile.is_open()) {
    myfile << "This is a file named " << file_name;
    myfile.close();
  } else {
    std::cout << "Unable to open file";
  }
  return 0;
}

int readFile(const std::string& file_name) {
  std::string line;
  std::ifstream myfile(file_name);
  if (myfile.is_open()) {
    std::cout << "open the file: " << file_name << std::endl;
    while (getline(myfile, line)) {
      std::cout << line << '\n';
    }
    myfile.close();
  } else {
    std::cout << "Unable to open file\n";
  }

  return 0;
}

int main() {
  std::cout << "start to run read_write..." << std::endl;
  readFile("starlark/data_new.txt");

  return 0;
}