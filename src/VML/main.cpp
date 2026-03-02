
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Chen Yuxuan

#include "../../libs/stddef.hpp"
#include "../../libs/algorithm.hpp"
#include "../../libs/functions.hpp"
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <fstream>
#include <string>

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
    using std::string, std::vector, std::array, std::ios, std::ifstream;
    ui32 argnum = (ui32)argc;
    vector<string> argvec;
    for (ui32 index = 0; index < argnum; ++index)
        argvec.push_back(string(argv[index]));
    functionsInit();
    
    if (argnum < 2) {
         output("vml program.vmlc\n");
         return 0;
    }
    
    string path = argvec[1];
    ifstream fin(path, ios::binary);
    
    Array<ui8, 0xA0000> memory;
    
    string program = load_file(path.c_str());
    vector<string> groups;
    for (int i = 0; i < program.length(); )
    // TODO： Load the whole program and excute it.
    
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
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*/
