// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Chen Yuxuan

#include "functions.hpp"
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdlib>

#define DEBUG

#ifdef DEBUG
    #include <iostream>
    using std::cout, std::endl;
#endif

char *load_file(const char* path) {
    std::ifstream ifs(path, std::ios::binary | std::ios::ate);
    if (!ifs) return nullptr;
    std::streamsize size = ifs.tellg();
    ifs.seekg(0);

    char *content = new char[static_cast<size_t>(size) + 1];
    if (size > 0)
        ifs.read(content, size);
    content[size] = '\0';
    return content;
}

int main(int argc, char *argv[]) {
    // Builds argnum and argvec first
    using std::string, std::vector, std::array, std::ios, std::ifstream, std::pair;
    ui32 argnum = (ui32)argc;
    vector<string> argvec;
    for (ui32 index = 0; index < argnum; ++index)
        argvec.push_back(string(argv[index]));
    functionsInit();
    
    if (argnum < 2) {
        output("vml program.vmlc\n");
        return 0;
    }
    
    // Some static varibles
    static const string magicString = "This is vml's.";
    static const ui8 magicStringLength = magicString.length();
    
    // varible
    string &path = argvec[1]; // get path
    ifstream fin(path, ios::binary); // Open the file
    if (!fin) {
        output("Cannot open file.\n");
        return -1;
    }
    fin.seekg(0, ios::end);
    std::streamsize s_size = fin.tellg();
    if (s_size < 0) {
        output("Failed to get file size.\n");
        return -1;
    }
    ui32 programLength = static_cast<ui32>(s_size);
    fin.seekg(0);
    Array<ui8, 0xA0000> memory; // Memory, 0xa0000 bytes
    char *program = load_file(path.c_str()); // load program
    if (!program) {
        output("Failed to read file.\n");
        return -1;
    }
    vector<pair<ui16, ui8*>> groups;
    ui8 readCharNumber;
    auto start = program;
    auto end = program + programLength;
    auto location = start;
    ui16 cmd;
    string datas;
    pair<ui16, ui8*> group;
    
    string fileString = string(program, magicStringLength);
    if (fileString != magicString) {
        output("This is not a vml program.\n");
        flush();
        return -1;
    }

    for (ui64 i = magicStringLength; i < programLength;) {
        // Make some groups for this program
        readCharNumber = static_cast<ui8>(program[i]); // Theoretically, ui8 and char is same. But i8 type lookblike a number.
        datas = string(
            start + i + 1,
            start + i + 1 + readCharNumber
        );

        if (datas.size() >= 2) 
            cmd = (static_cast<ui16>(datas[0]) << 8) | static_cast<ui8>(datas[1]);
        else 
            throw std::runtime_error("Invalid command data size.");

        ui8* data_ptr = nullptr;
        if (datas.size() > 2) {
            data_ptr = (ui8*)std::malloc(datas.size() - 2);
            if (data_ptr)
                std::memcpy(data_ptr, datas.data() + 2, datas.size() - 2);
        }

        cout << "Read command " << cmd << " with data size " << datas.size() - 2 << ".\n";

        groups.push_back(pair<ui16, ui8*>(cmd, data_ptr)); // push datas to groups
        i += readCharNumber + 1; // Jump next location
    }

    for (ui32 i = 0; i < groups.size();) { // Use some function to change the i as ptr
        group = groups[i];
        #ifdef DEBUG
            cout << "Executing command " << group.first << "...\n";
        #endif
        functions[group.first](group.second, memory, i);
    }

    for (auto& p : groups) 
        std::free(p.second);
    
    return 0;
}

/*
                           _ooOoo_
                          o8888888o
                          88" . "88
                          (| -_- |)
                          O\  =  /O
                       ____/`---'\____
                     .'  \\|     |//  `.
                    /  \\|||  :  |||//  \
                   /  _||||| -:- |||||-  \
                   |   | \\\  -  /// |   |
                   | \_|  ''\---/''  |   |
                   \  .-\__  `-`  ___/-. /
                 ___`. .'  /--.--\  `. . __
              ."" '<  `.___\_<|>_/___.'  >'"".
             | | :  `- \`.;`\ _ /`;.`/ - ` : | |
             \  \ `-.   \_ __\ /__ _/   .-` /  /
        ======`-.____`-.___\_____/___.-`____.-'======
                           `=---='
       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*/
