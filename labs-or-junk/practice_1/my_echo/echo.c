/**
#include <stdio.h>

int main(int argc, char **argv) {
    
    for (int i = 1; i < argc; i++) {
        printf(i < argc - 1 ? "%s " : "%s", argv[i]);
    }
    puts("");

    return 0;
}
**/

/**
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    
    for (int i = 1; i < argc; i++) {
        write(STDOUT_FILENO, argv[i], strlen(argv[i]));
        if (i + 1 < argc) {
            write(STDOUT_FILENO, " ", 1);
        }
    }
    write(STDIN_FILENO, "\n", sizeof("\n") - 1);
    
    return 0;
}
**/

long my_write(int fd, const void *buf, unsigned long count) {
    long result;

    __asm__ __volatile__ (
        "mov $0x1, %%rax\n\t"
        "syscall"
        :
        "=a" (result)
    );

    return result;
}

unsigned long my_strlen(const char *s) {
    const char *start = s; for ( ; *s; ++s);
    return (unsigned long) (s - start);
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        my_write(1, argv[i], my_strlen(argv[i]));
        if (i + 1 < argc) {
            my_write(1, " ", 1);
        }
    }
    my_write(1, "\n", sizeof("\n") - 1);

    return 0;
}