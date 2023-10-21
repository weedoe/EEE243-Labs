#include <stdio.h>
int power(int base, int exp);
int main() {
    int base;
    int exp;
    printf("Enter a number: ");
    scanf("%d", &base);  // NOLINT(*-err34-c)
    printf("Enter the exponent: ");
    scanf("%d", &exp);  // NOLINT(*-err34-c)
    power(base, exp); //power calculation function
}
int power(int base, int exp){
    int result = 1;
    for (int i = 0; i < exp; i++){
        result = result * base;
    }
    printf("%d^%d = %d\n", base, exp, result);
    return 0;
}