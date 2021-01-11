#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv) {
    int pid = fork();
    if (pid == 0) {
        write(1, "A\n", sizeof("A\n") - 1);
    } else {
        write(1, "B\n", sizeof("B\n") - 1);
    }
}