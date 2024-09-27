#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("usage: %s filename\n", argv[0]);
        return -1;
    }

    struct stat statbuf;

    if (stat(argv[1], &statbuf)) {
        perror("stat() failed\n");
        return -1;
    }
    
    printf("file name: %s\n", argv[1]);
    printf("size: %lld\n", statbuf.st_size);
    
    if (S_ISDIR(statbuf.st_mode)) {
        printf("It is directory.\n");
    } else if (S_ISREG(statbuf.st_mode)) {
        printf("It is regular file.\n");
    } else {
        printf("???\n");
    }

    return 0;
}

// 파일의 이름을 인자로 받아오고 해당 파일의 속성을 읽어보기