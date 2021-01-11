#include <unistd.h>
#include <string.h>

#define BUFF_SIZE 4096
static char buff[BUFF_SIZE];

int main(int argc, char** argv) {
    getcwd(buff, BUFF_SIZE);
    write(1, buff, strnlen(buff, BUFF_SIZE));
    write(1, "\n", sizeof("\n") - 1);
    return 0;
}