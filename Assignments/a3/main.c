#include <stdio.h>
int pyramid(int num1);
float ftoc(float num2);
int power(int base, int exp);
int isLeap(int year);

int main() {
    int num1;
    printf("Enter the number of rows: ");
    scanf("%d", &num1);  // NOLINT(*-err34-c)
    pyramid(num1); //pyramid loop function

    float num2;
    printf("Enter a temperature in F: ");
    scanf("%f", &num2);  // NOLINT(*-err34-c)
    ftoc(num2); //F to C conversion function

    int base;
    int exp;
    printf("Enter a number: ");
    scanf("%d", &base);  // NOLINT(*-err34-c)
    printf("Enter the exponent: ");
    scanf("%d", &exp);  // NOLINT(*-err34-c)
    power(base, exp); //power calculation function

    int year;
    printf("Enter a year: ");
    scanf("%d", &year);  // NOLINT(*-err34-c)
    isLeap(year); //leap year indicator function
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

float ftoc(float num2){
    float num3;
    num3 = (num2 - 32) * 5 / 9;
    printf("%0.2f F is %0.2f C\n", num2, num3);
    return 0;
}

int power(int base, int exp){
    int result = 1;
    for (int i = 0; i < exp; i++){
        result = result * base;
    }
    printf("%d^%d = %d\n", base, exp, result);
    return 0;
}

int isLeap(int year){
    if (year % 4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0){
                printf("%d is a leap year\n", year);
            }
            else{
                printf("%d is not a leap year\n", year);
            }
        }
        else{
            printf("%d is a leap year\n", year);
        }
    }
    else{
        printf("%d is not a leap year\n", year);
    }
    return 0;
}



