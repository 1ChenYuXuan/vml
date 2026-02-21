
#include "../../libs/stddef.hpp"
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    // Builds argnum and argvec first
    using std::string, std::vector;
    ui32 argnum = (ui32)argc;
    vector<string> argvec;
    for (ui32 index = 0; index < argnum; ++index)
        argvec.push_back(string(argv[index]));
    
    return 0;
}
