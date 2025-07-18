#include <iostream>
#include <string>

#include "file_reader.hpp"

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cerr << "No file specified!" << std::endl;
        return 1;
    }

    FileReader file_reader;
    std::string path(argv[1]);
    file_reader.readFile(path);

    
    return 0;
}