#include <stdio.h>

int main() {
    int num = 5;
    int *p_int;
    printf("%s", "Content of num: ");
    printf("%d\n", num);
    printf("%s", "Address of num: ");
    printf("%p\n", &num);
    printf("%s", "Content of p_int: ");
    printf("%p\n", p_int);
    printf("%s", "Address of p_int: ");
    printf("%p\n", &p_int);
    p_int = &num;
    *p_int = 10;
    printf("%s", "Content of num: ");
    printf("%d\n", num);
    printf("%s", "Address of num: ");
    printf("%p\n", &num);
    printf("%s", "Content of p_int: ");
    printf("%p\n", p_int);
    printf("%s", "Address of p_int: ");
    printf("%p\n", &p_int);
    printf("%s", "Contents to which p_int refers: ");
    printf("%d\n", *p_int);
    return 0;



}
