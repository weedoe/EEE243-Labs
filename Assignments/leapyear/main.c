#include <stdio.h>
int isLeap(int year);
int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);  // NOLINT(*-err34-c)
    isLeap(year); //leap year indicator function
}
int isLeap(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                printf("%d is a leap year", year);
            } else {
                printf("%d is not a leap year", year);
            }
        } else {
            printf("%d is a leap year", year);
        }
    } else {
        printf("%d is not a leap year", year);
    }
    return 0;
}