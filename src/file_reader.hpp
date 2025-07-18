#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

struct FileReader{
    void readFile(std::string& path){
        std::ifstream file(path);
        if(!file.is_open()){
            std::cerr << "No such file exists: " << path << std::endl;
            exit(1);
        }

        std::stringstream buffer;
        buffer << file.rdbuf();

        data = buffer.str();
        file.close();
    }

    std::string data;
};