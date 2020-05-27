#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

int main(int argc, char *argv[]) {
    //Assign the command line argument to path
    string path = argv[1];
    //List files in directory
    for (const auto &entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
}