#include <stdio.h>
int pyramid(int num1);
int main() {
    int num1;
    printf("Enter the number of rows:\n");
    scanf("%d", &num1);  // NOLINT(*-err34-c)
    pyramid(num1); //pyramid loop function
}
int pyramid(int num1) {
    char blocks[] = "*";
    for (int i = 0; i < num1; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%s", blocks);
        }
        printf("\n");
    }
    return 0;
}
