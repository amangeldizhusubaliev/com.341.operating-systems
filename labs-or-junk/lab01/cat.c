#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 131072
static char buff[BUFF_SIZE];

int main(int argc, char** argv) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            int fd = openat(AT_FDCWD, argv[i], O_RDONLY);
            ssize_t rd = 0;
            while ((rd = read(fd, buff, BUFF_SIZE)) > 0) {
                write(STDOUT_FILENO, buff, rd);
            }
            close(fd);
        }
    } else {
        ssize_t rd = 0;
        while ((rd = read(STDIN_FILENO, buff, BUFF_SIZE)) > 0) {
            write(STDOUT_FILENO, buff, rd);
        }
    }
    return 0;
}