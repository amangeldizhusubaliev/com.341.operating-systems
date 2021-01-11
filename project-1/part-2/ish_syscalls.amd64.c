long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     )
{
    long res = -1;

    __asm__ __volatile__ (
        "xor %%rax, %%rax\n\t"
        "syscall\n\t"
        : "=a"(res)
    );

    return res;
}

int ish_chdir(const char *path)
{
    int res = -1;

    __asm__ __volatile__ (
        "mov $80, %%rax\n\t"
        "syscall\n\t"
        : "=a"(res) 
    );

    return res;
}

void ish_exit(int status)
{
    __asm__ __volatile__ (
        "mov $60, %%rax\n\t"
        "syscall\n\t"
        :
        :
        : "%rax"
    );
}

int ish_stat(const char *path, void *stat_result)
{
    int res = -1;

    __asm__ __volatile__ (
        "mov $4, %%rax\n\t"
        "syscall\n\t"
        : "=a"(res)
    );

    return res;
}

int ish_open(const char *path, int flags)
{
    int res = -1;

    __asm__ __volatile__ (
        "mov $2, %%rax\n\t"
        "syscall\n\t"
        : "=a"(res)
    );

    return res;
}

int ish_creat(const char *path, unsigned int mode)
{
    int res = -1;

    __asm__ __volatile__ (
        "mov $85, %%rax\n\t"
        "syscall\n\t"
        : "=a"(res)
    );

    return res;
}

int ish_dup2(int old_file_descriptor, int new_file_descriptor)
{
    int res = -1;

    __asm__ __volatile__ (
        "mov $33, %%rax\n\t"
        "syscall\n\t"
        : "=a"(res)
    );

    return res;
}

int ish_close(int file_descriptor)
{
    int res = -1;

    __asm__ __volatile__ (
        "mov $3, %%rax\n\t"
        "syscall\n\t"
        : "=a"(res)
    );

    return res;
}

int ish_fork()
{
    int res = -1;

    __asm__ __volatile__ (
        "mov $57, %%rax\n\t"
        "syscall\n\t"
        : "=a"(res)
    );

    return res;
}

int ish_execve(
        const char *path,
        char *const arguments[],
        char *const environment[]
    )
{
    int res = -1;

    __asm__ __volatile__ (
        "mov $59, %%rax\n\t"
        "syscall\n\t"
        : "=a"(res)
    );

    return res;
}

int ish_waitpid(int pid, int *status, int options)
{
    int res = -1;

    __asm__ __volatile__ (
        "mov $61, %%rax\n\t"
        "xor %%r10, %%r10\n\t"
        "syscall"
        : "=a"(res)
        :
        : "%r10"
    );

    return -1;
}

long ish_write(
        int file_descriptor,
        const void *buffer,
        unsigned long buffer_size
     )
{
    long res = -1;

    __asm__ __volatile__ (
        "mov $1, %%rax\n\t"
        "syscall\n\t"
        : "=r"(res)
    );

    return res;
}
