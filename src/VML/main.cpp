
#include "../../libs/stddef.hpp"
#include "../../libs/algorithm.hpp"
#include <string>
#include <array>
#include <vector>

int main(int argc, char *argv[]) {
    // Builds argnum and argvec first
    using std::string, std::vector, std::array, ios::binary;
    ui32 argnum = (ui32)argc;
    vector<string> argvec;
    for (ui32 index = 0; index < argnum; ++index)
        argvec.push_back(string(argv[index]));
    
    if (argnum < 2) {
         output("vml program.vmlc\n");
         return 0;
    }
    
    vector<ui16> registersPlace;
    path = argvec[1];
    ifstream fin(path, binary);
    
    while (1)
    {
        
    }
    
    return 0;
}
