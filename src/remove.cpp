#include "./remove.hpp"

void del_files(std::string filename, bool iferr = false) {
    if (iferr == true) {
        std::string command = "rm -f " + filename;
        std::system(command.c_str());
    } else {
        std::system("rm -f out.o out.asm");
    }
}
