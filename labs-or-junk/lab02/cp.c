#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFF_SIZE 131072
static char buff[BUFF_SIZE];

int main(int argc, char** argv) {
    if (argc == 3) {
        int in_fd = openat(AT_FDCWD, argv[1], O_RDONLY);
        int out_fd = openat(AT_FDCWD, argv[2], O_WRONLY | O_CREAT | O_EXCL, 0664);
        unsigned long r;
        while ((r = read(in_fd, buff, BUFF_SIZE)) > 0) {
            write(out_fd, buff, r);
        }
        close(in_fd);
        close(out_fd);
    }
    return 0;
}