#include <iostream>

#define LOG(level) std::cerr
#define VLOG(level) \
    if (true)       \
    {               \
    }               \
    else            \
        std::cerr

int main()
{
    LOG(1) << "this is a LOG(1)";
    VLOG(1) << "this is a VLOG(1)";

    std::cout << "this is a test" << std::endl;
    return 0;
}