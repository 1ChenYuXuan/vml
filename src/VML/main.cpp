
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Chen Yuxuan

#include "../../libs/stddef.hpp"
#include "../../libs/algorithm.hpp"
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
    
    if (argnum < 2) {
         output("vml program.vmlc\n");
         return 0;
    }
    
    vector<ui16> registersPlace;
    string path = argvec[1];
    ifstream fin(path, ios::binary);
    
    while (1)
    {
        
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
