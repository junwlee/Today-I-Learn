#include <iostream>
#include <sys/stat.h>

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) {
        cerr << "usage: " << argv[0] << " filename" << endl;
        return -1;
    }

    struct stat statbuf;

    if (stat(argv[1], &statbuf)) {
        perror("stat() failed");
        return -1;
    }

    cout << "filename: " << argv[1] << endl;
    cout << "size: " << statbuf.st_size << endl;

    switch (statbuf.st_mode & S_IFMT) {
        case S_IFDIR:
            cout << "It is directory" << endl;
            break;
        case S_IFREG:
            cout << "It is regular file" << endl;
            break;
        default:
            cout << "???" << endl;
            break;
    }
    
    return 0;
}