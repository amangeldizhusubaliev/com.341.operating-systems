long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     )
{
    register long res asm("v0");

    __asm__ __volatile__ (
    	"li $v0, 5000\n\t"
		"syscall\n\t"
		: "=r"(res)
    );

    return res;
}

int ish_chdir(const char *path)
{
    register int res asm("v0");

    __asm__ __volatile__ (
    	"li $v0, 5078\n\t"
		"syscall\n\t"
		: "=r"(res)
    );

    return res;
}

void ish_exit(int status)
{
    __asm__ __volatile__ (
		"li $v0, 5058\n\t"
		"syscall\n\t"
		:
		:
		: "v0"
    );
}

int ish_stat(const char *path, void *stat_result)
{
    register int res asm("v0");

    __asm__ __volatile__ (
    	"li $v0, 5004\n\t"
		"syscall\n\t"
		: "=r"(res)
    );

    return res;
}

int ish_open(const char *path, int flags)
{
    register int res asm("v0");

    __asm__ __volatile__ (
    	"li $v0, 5002\n\t"
		"syscall\n\t"
		: "=r"(res)
    );

    return res;
}

int ish_creat(const char *path, unsigned int mode)
{
    register int res asm("v0");

    __asm__ __volatile__ (
    	"li $v0, 5083\n\t"
		"syscall\n\t"
		: "=r"(res)
    );

    return res;
}

int ish_dup2(int old_file_descriptor, int new_file_descriptor)
{
    register int res asm("v0");

    __asm__ __volatile__ (
    	"li $v0, 5286\n\t"
		"li $a2, 0\n\t"
		"syscall\n\t"
		: "=r"(res)
		:
		: "a2"
    );

    return res;
}

int ish_close(int file_descriptor)
{
    register int res asm("v0");

    __asm__ __volatile__ (
    	"li $v0, 5003\n\t"
		"syscall\n\t"
		: "=r"(res)
    );

    return res;
}

int ish_fork()
{
    register int res asm("v0");

    __asm__ __volatile__ (
    	"li $v0, 5056\n\t"
		"syscall\n\t"
		: "=r"(res)
    );

    return res;
}

int ish_execve(
        const char *path,
        char *const arguments[],
        char *const environment[]
    )
{
    register int res asm("v0");

    __asm__ __volatile__ (
    	"li $v0, 5057\n\t"
		"syscall\n\t"
		: "=r"(res)
    );

    return res;
}

int ish_waitpid(int pid, int *status, int options)
{
    register int res asm("v0");

    __asm__ __volatile__ (
    	"li $v0, 5059\n\t"
		"li $a3, 0\n\t"
		"syscall\n\t"
		: "=r"(res)
		:
		: "a3"
    );

    return res;
}

long ish_write(
        int file_descriptor,
        const void *buffer,
        unsigned long buffer_size
     )
{
    register int res asm("v0");

    __asm__ __volatile__ (
    	"li $v0, 5001\n\t"
		"syscall\n\t"
		: "=r"(res)
    );

    return res;
}
