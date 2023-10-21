#include <stdio.h>
int main() {
    char blocks[] = "*";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%s", blocks);
        }
        printf("\n");
    }
}