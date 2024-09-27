#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// 바이트 스트림에 적합한 구조체 정의
struct Person {
    char name[16];
    int age;
};

// 사람 정보를 파일에 추가하는 함수
static int write_info(struct Person *p) {
    int fd = open("person_info", O_CREAT | O_WRONLY | O_APPEND, 0644);  // 파일이 없으면 생성, 쓰기 전용, 끝에 추가

    if (fd == -1) {
        perror("open() failed");
        return -1;
    }

    ssize_t ret = write(fd, p, sizeof(struct Person));

    if (ret == -1) {
        perror("write() failed");
        close(fd);
        return -1;
    } else if (ret != sizeof(struct Person)) {
        fprintf(stderr, "Partial write occurred\n");
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}

// 저장된 사람 정보를 출력하는 함수
static int dump_info(void) {
    int fd = open("person_info", O_RDONLY);  // 읽기 전용으로 파일 열기

    if (fd == -1) {
        perror("open() failed");
        return -1;
    }

    struct Person p;
    ssize_t ret;

    // 파일에서 데이터를 읽어들여 출력
    while (1) {
        ret = read(fd, &p, sizeof(struct Person));

        if (ret == -1) {
            perror("read() failed");
            close(fd);
            return -1;
        } else if (ret == 0) {// EOF 처리
            FILE *fp = fdopen(fd, "r"); // fdopen: fd를 포인터로 변환
            if (fp == NULL) {
                printf("fdopen fail\n");
                close(fd);
                return -1;
            }

            printf("file position = %ld\n", ftell(fp));
            fclose(fp);

            break;  
        } else if (ret != sizeof(struct Person)) {
            fprintf(stderr, "Partial read occurred\n");
            close(fd);
            return -1;
        }

        printf("Name: %s, Age: %d\n", p.name, p.age);
    }

    close(fd);
    return 0;
}

int main(void) {
    struct Person persons[] = {
        {"kim", 40},
        {"mike", 23}
    };

    // 사람 정보를 파일에 기록
    if (write_info(&persons[0]) == -1) {
        return -1;
    }

    if (write_info(&persons[1]) == -1) {
        return -1;
    }

    // 파일에 기록된 사람 정보를 출력
    if (dump_info() == -1) {
        return -1;
    }

    return 0;
}
