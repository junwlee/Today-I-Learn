#include <iostream>
#include <cstdlib>
#include <unistd.h>  // link()와 symlink() 함수에 필요

#define TARGET_FILE "hello_world"

int main(int argc, char **argv) {
    if (link(TARGET_FILE, "hello_by_link")) {
        perror("link() failed");
        return -1;
    }

    if (symlink(TARGET_FILE, "hello_by_symlink")) {
        perror("symlink() failed");
        return -1;
    }
    
    return 0;
}