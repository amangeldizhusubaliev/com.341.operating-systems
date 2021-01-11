long my_write(int fd, const void* buf, unsigned long len) {
    long res;
    __asm__ __volatile__ (
        "mov $1, %%rax\n\t"
        "syscall\n\t"
        : "=a"(res)
    );
    return res;
}

unsigned long my_strlen(const char* s) {
    const char* i = s; for (; *i; i++);
    return (unsigned long) (i - s);
}

int main(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        my_write(1, argv[i], my_strlen(argv[i]));
        if (i + 1 < argc) {
            my_write(1, " ", 1);
        }
    }
    my_write(1, "\n", sizeof("\n") - 1);
    return 0;
}