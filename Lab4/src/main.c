#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <stdio.h>
#include "stringlib.h"
int choice;
bool compareArrays(const char* generated, const char* desired, int size) {
    for (int i = 0; i < size; i++) {
        if (generated[i] != desired[i]) {
            return false; // Arrays don't match
        }
    }
    return true; // Arrays match
}
int main() {
    while (choice != 14) {
        printf("count_chars [0]\n"
               "trim_right [1]\n"
               "trim_left [2]\n"
               "pad_right [3]\n"
               "pad_left [4]\n"
               "center [5]\n"
               "is_palindrome [6]\n"
               "truncate [7]\n"
               "capitalize [8]\n"
               "capitalize_words [9]\n"
               "is_alpha [10]\n"
               "reverse [11]\n"
               "count_occurrences [12]\n"
               "delete_char [13]\n"
               "exit [14]\n"
               "Enter a number to choose a test:\n");
        scanf("%d", &choice);
        if(choice == 0) {
            char *test[0];
            test[0] = "test";
            printf("%d\n", count_chars(test[0]));
            if(count_chars(test[0]) == 4){
                printf("Test case 1 passed.\n");
            }
            else{
                printf("Test case 1 failed.\n");
            }
            test[0] = "test test";
            printf("%d\n", count_chars(test[0]));
            if(count_chars(test[0]) == 9){
                printf("Test case 2 passed.\n");
            }
            else{
                printf("Test case 2 failed.\n");
            }
            printf("\n");
        }
        if(choice == 1) {
            char test[] = "test ";
            char desired[] = "test";
            trim_right(test);
            if(compareArrays(test, desired, 3)){
                printf("Test case 1 passed.\n");
            }
            else{
                printf("Test case 1 failed.\n");
            }
            char test2[] = "test test  ";
            char desired2[] = "test test ";
            trim_right(test2);
            if(compareArrays(test2, desired2, 8)){
                printf("Test case 2 passed.\n\n");
            }
            else{
                printf("Test case 2 failed.\n\n");
            }
        }
        if (choice == 2){
            char test[] = " test";
            char desired[] = "test";
            trim_left(test);
            if(compareArrays(test, desired, 3)){
                printf("\nTest case 1 passed.\n");
            }
            else{
                printf("\nTest case 1 failed.\n");
            }
            char test2[] = " test test";
            char desired2[] = "test test";
            trim_left(test2);
            if(compareArrays(test2, desired2, 8)){
                printf("\nTest case 2 passed.\n\n");
            }
            else{
                printf("\nTest case 2 failed.\n\n");
            }
        }
        if (choice == 3){
            char test[] = "test";
            char test2[] = "test";
            char desired[] = "test  ";
            char desired2[] = "test";
            int n = 6;
            int n2 = 4;
            pad_right(test, n);
            if(compareArrays(test, desired, 7)){
                printf("\nTest case 1 passed.\n");
            }
            else{
                printf("\nTest case 1 failed.\n");
            }
            pad_right(test2, n2);
            if(compareArrays(test2, desired2, 5)){
                printf("\nTest case 2 passed.\n\n");
            }
            else{
                printf("\nTest case 2 failed.\n\n");
            }

        }
        if (choice == 4){
            char test[] = "test";
            char test2[] = "test";
            char desired[] = "  test";
            char desired2[] = "test";
            int n = 6;
            int n2 = 4;
            pad_left(test, n);
            if(compareArrays(test, desired,7)){
                printf("\nTest case 1 passed.\n");
            }
            else{
                printf("\nTest case 1 failed.\n");
            }
            pad_left(test2, n2);
            if(compareArrays(test2, desired2, 5)){
                printf("\nTest case 2 passed.\n\n");
            }
            else{
                printf("\nTest case 2 failed.\n\n");
            }

        }
        if (choice == 5){
            char test[] = "test";
            char test2[] = "test";
            char desired[] = " test ";
            char desired2[] = " test  ";
            int n = 6;
            int n2 = 7;
            center(test, n);
            if(compareArrays(test, desired, 7)){
                printf("\nTest case 1 passed.\n");
            }
            else{
                printf("\nTest case 1 failed.\n");
            }
            center(test2, n2);
            if(compareArrays(test2, desired2, 8)){
                printf("\nTest case 2 passed.\n\n");
            }
            else{
                printf("\nTest case 2 failed.\n\n");
            }

        }
        if (choice == 6){
            char test[] = "RADar";
            printf("%d\n", is_palindrome(test));
            if(is_palindrome(test) == 1){
                printf("Test case 1 passed.\n");
            }
            else{
                printf("Test case 1 failed.\n");
            }
        }
        if (choice == 7){
            char test[] = "test";
            char desired[] = "te";
            char test2[] = "test";
            char desired2[] = "test";
            int n = 2;
            int n2 = 4;
            truncate(test, n);
            if(compareArrays(test, desired, 3)){
                printf("\nTest case 1 passed.\n");
            }
            else{
                printf("\nTest case 1 failed.\n");
            }
            truncate(test2, n2);
            if(compareArrays(test2, desired2, 5)){
                printf("\nTest case 2 passed.\n\n");
            }
            else{
                printf("\nTest case 2 failed.\n\n");
            }
        }
        if (choice == 8){
            printf("Enter a string to capitalize first letter:\n");
            char *test[0];
            scanf("%s", test[0]);
            capitalize(test[0]);
        }
        if (choice == 9){
            printf("Enter a string to capitalize words:\n");
            char *test[0];
            scanf("%s", test[0]);
            capitalize_words(test[0]); //end work for now, bugs to be fixed l8r
        }
    }
}
