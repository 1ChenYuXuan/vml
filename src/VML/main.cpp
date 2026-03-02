// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Chen Yuxuan

#include "functions.hpp"
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <fstream>
#include <string>
#include <utility>
#include <cstring>
#include <cstdlib>

std::string load_file(const char* path) {
    std::ifstream ifs(path, std::ios::binary | std::ios::ate);
    std::streamsize size = ifs.tellg();
    ifs.seekg(0);

    std::string content(size, '\0');
    ifs.read(&content[0], size);
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
    Array<ui8, 0xA0000> memory; // Memory, 0xa0000 bytes
    string program = load_file(path.c_str()); // load program
    vector<pair<ui16, ui8*>> groups;
    ui32 programLength = program.length();
    ui8 readCharNumber;
    auto start = program.begin();
    auto end = program.end();
    auto location = start;
    ui16 cmd;
    string datas;
    pair<ui16, ui8*> group;
    
    string fileString = string(program.begin(), program.begin() + magicStringLength);
    if (fileString != magicString) {
        output("This is not a vml program.\n");
        flush();
        return -1;
    }
    
    for (ui64 i = magicStringLength; i < programLength;) {
        // Make some groups for this program
        readCharNumber = static_cast<ui8>(program[i]); // Theoretically, i8 and char is same. But i8 type lookblike a number.
        datas = string(
            program.begin() + i + 1,
            program.begin() + i + 1 + readCharNumber
        );

        if (datas.size() >= 2) 
            std::memcpy(&cmd, datas.data(), 2);
        else 
            cmd = 0;

        ui8* data_ptr = (ui8*)std::malloc(datas.size() - 2);
        if (data_ptr && datas.size() > 2) {
            std::memcpy(data_ptr, datas.data() + 2, datas.size() - 2);
        }

        groups.push_back(pair<ui16, ui8*>(cmd, data_ptr)); // push datas to groups
        i += readCharNumber + 1; // Jump next location
    }

    for (ui32 i = 0; i < groups.size();) { // Use some function to change the i as ptr
        group = groups[i];
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
