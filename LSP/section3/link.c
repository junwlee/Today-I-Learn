#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Include for link() and symlink()

#define TARGET_FILE "hello_world"

int main(int argc, char **argv) {
    if (link(TARGET_FILE, "hello_by_link")) {
        perror("link() failed");
        return -1;
    }

    if (symlink(TARGET_FILE, "hello_by_symlink")) {
        perror("link() failed");
        return -1;
    }

    return 0;
}