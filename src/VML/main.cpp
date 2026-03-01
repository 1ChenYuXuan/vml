
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Chen Yuxuan

#include "../../libs/stddef.hpp"
#include "../../libs/algorithm.hpp"
#include "../../libs/functions.hpp"
#include <fstream>
#include <string>
#include <array>
#include <vector>

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
    char readNum[1];
    char arguments[256];
    char *argsp = arguments;
    bool isOver;
    ui16 cmd;
    while (1)
    {
        fin.read(readNum, 1);
        isOver = !fin;
        if (isOver)
            return 0;
        
        fin.read(arguments, readNum[0]);
        cmd = *(ui16*)argsp;
        argsp += 2;
        functions[cmd](argsp, memory);
    }
    
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
