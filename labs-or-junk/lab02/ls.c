#include <sys/syscall.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct linux_dirent 
{
	long inode;
	off_t offset;
	unsigned short reclen;
	char name[];
} linux_dirent_t; 

#define BUFF_SIZE 1024
static char buff[BUFF_SIZE];

int main(int argc, char** argv) {
    int fd = open(argc > 1 ? argv[1] : ".", O_RDONLY | O_DIRECTORY);
    int entries;
    while ((entries = syscall(SYS_getdents, fd, buff, BUFF_SIZE)) > 0) {
        for (int entry = 0; entry < entries; ) {
            linux_dirent_t* data = (linux_dirent_t*) (buff + entry);
            if (!(strncmp(data->name, ".", 1) == 0 || strncmp(data->name, "..", 2) == 0)) {
                write(STDOUT_FILENO, data->name, strlen(data->name));
                write(STDOUT_FILENO, " ", 1);
            }
            entry += data->reclen;
        }
    }
    write(STDOUT_FILENO, "\n", sizeof("\n") - 1);   
    close(fd);
    return 0;
}