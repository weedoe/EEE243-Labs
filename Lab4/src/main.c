#include <stdio.h>
#include <stdlib.h>
#include "stringlib.h"
int choice;
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
            printf("Enter a string to be counted:\n");
            char *test[0];
            test[0] = malloc(sizeof(test));
            scanf("%s", test[0]);
            printf("%d", count_chars(test[0]));
            printf("\n");
        }
        if(choice == 1){
            printf("Enter a string to trim the right:\n");
            char *test[0];
            test[0] = malloc(sizeof(test));
            scanf("%s", test[0]);
            trim_right(test[0]);
        }
        if (choice == 2){
            printf("Enter a string to trim the left:\n");
            char *test[0];
            test[0] = malloc(sizeof(test));
            scanf("%s", test[0]);
            trim_left(test[0]);
        }
        if (choice ==3){
            printf("Enter a string to pad the right:\n");
            char *test[0];
            test[0] = malloc(sizeof(test));
            scanf("%s", test[0]);
            printf("Enter a number to pad the right:\n");
            int n;
            scanf("%d", &n);
            pad_right(test[0], n);
        }
        if (choice == 4){
            printf("Enter a string to pad the left:\n");
            char *test[0];
            test[0] = malloc(sizeof(test));
            scanf("%s", test[0]);
            printf("Enter a number to pad the left:\n");
            int n;
            scanf("%d", &n);
            pad_left(test[0], n);

        }
    }
}
