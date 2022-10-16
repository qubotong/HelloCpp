#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

int writeFile(const char* file_name, const char* str) {
  std::cout << "try to write to the file:" << file_name << std::endl;
  std::ofstream myfile(file_name);
  if (myfile.is_open()) {
    auto timenow =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    myfile << ctime(&timenow);
    myfile << str << std::endl;
    myfile.close();
    std::cout << "successfully!" << std::endl;
  } else {
    std::cout << "Unable to write to the file:" << file_name << std::endl;
  }
  return 0;
}

int readFile(const char* file_name) {
  std::cout << "try to read the file:" << file_name << std::endl;
  std::string line;
  std::ifstream myfile(file_name, std::ifstream::in);
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      std::cout << line << '\n';
    }
    myfile.close();
  } else {
    std::cout << "Unable to read the file:" << file_name << std::endl;
  }

  return 0;
}

int main(int argc, char** argv) {
  std::cout << "start read and write program..." << std::endl;

  std::cout << "arguments:" << std::endl;
  for (int i = 0; i < argc; ++i) {
    std::cout << argv[i] << "\n";
  }

  writeFile(argv[1], argv[2]);
  readFile(argv[1]);

  return 0;
}