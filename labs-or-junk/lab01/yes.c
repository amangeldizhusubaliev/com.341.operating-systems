#include <stdio.h>

int main(int argc, char** argv) {
    if (argc > 1) {
        while (1) {
            for (int i = 1; i < argc; i++) {
                printf("%s%c", argv[i], " \n"[i + 1 == argc]);
            }
        }
    } else {
        while (1) {
            puts("y");
        }
    }
    return 0;
}