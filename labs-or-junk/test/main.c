#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int a;
    char b;
} node_t;

int main(int argc, char **argv) {
    node_t *a = (node_t *) malloc(sizeof(node_t) * 10);
    for (int i = 0; i < 5; i++) {
        (a + i + 5) -> a = i + 1;
        (a + i + 5) -> b = 'a' + i;
    }
    memmove(a + 2, a + 5, sizeof(node_t) * 5);
    for (int i = 0; i < 10; i++) {
        printf("%d %c\n", (a + i) -> a, (a + i) -> b);
    }
    puts("");
    return 0;
}