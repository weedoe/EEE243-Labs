/**
 * This C file has the purpose of testing the functions in stringlib.c. This is
 * accomplished by taking a numerical input from the user and running the
 * corresponding preset test case. The user can exit the program by entering 14.
 * A selection menu system is used to speed up the testing of every module.
 * The result of the tests are printed above the menu.
 *
 * Author: OCdt Paterson 30648
 * Version: October 31st 2023
 */

#pragma clang diagnostic push //ignoring scanf warning
#pragma ide diagnostic ignored "cert-err34-c" //ignoring scanf warning

#include <stdio.h>
#include "stringlib.h"

//function declaration
bool compare_arrays(const char *generated, const char *desired, int size);


/**
 * This function is the main function of the program. It takes a numerical input
 * from the user and runs the corresponding test case. The user can exit the
 * program by entering 14.
 */
int choice; //initializing choice variable for choice menu loop
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
               "Enter a number to choose a test:\n"); //choice menu
        scanf("%d", &choice); //takes user choice for test
        //choice 0, counting characters in string
        if (choice == 0) {
            char test[] = "test"; //initializing test array
            char test2[] = "test test";
            printf("%d\n", count_chars(test));
            if (count_chars(test) == 4) { //checks for correct return value
                //(4)
                printf("Test case 1 passed.\n");
            } else { //prints failed if return value is incorrect (not 4)
                printf("Test case 1 failed.\n");
            }
            printf("%d\n", count_chars(test2));
            if (count_chars(test2) == 9) {
                printf("Test case 2 passed.\n");
            } else {
                printf("Test case 2 failed.\n");
            }
            printf("\n");
        }
        //choice 1, trimming spaces off right of string
        if (choice == 1) {
            char test[] = "test ";
            char desired[] = "test";
            trim_right(test); //runs function
            //below runs compare function initialized above if (1) then passed
            //else (0), then failed
            if (compare_arrays(test, desired, 3)) {
                printf("Test case 1 passed.\n");
            } else {
                printf("Test case 1 failed.\n");
            }
            char test2[] = "test test  ";
            char desired2[] = "test test ";
            trim_right(test2);
            if (compare_arrays(test2, desired2, 8)) {
                printf("Test case 2 passed.\n\n");
            } else {
                printf("Test case 2 failed.\n\n");
            }
        }
        //choice 2, trimming spaces off left of string
        if (choice == 2) {
            char test[] = " test";
            char desired[] = "test";
            trim_left(test);
            if (compare_arrays(test, desired, 3)) {
                printf("\nTest case 1 passed.\n");
            } else {
                printf("\nTest case 1 failed.\n");
            }
            char test2[] = " test test";
            char desired2[] = "test test";
            trim_left(test2);
            if (compare_arrays(test2, desired2, 8)) {
                printf("\nTest case 2 passed.\n\n");
            } else {
                printf("\nTest case 2 failed.\n\n");
            }
        }
        //choice 3, padding spaces to right of string
        if (choice == 3) {
            char test[] = "test";
            char test2[] = "test";
            char desired[] = "test  ";
            char desired2[] = "test";
            int n = 6;
            int n2 = 4;
            pad_right(test, n);
            if (compare_arrays(test, desired, 7)) {
                printf("\nTest case 1 passed.\n");
            } else {
                printf("\nTest case 1 failed.\n");
            }
            pad_right(test2, n2);
            if (compare_arrays(test2, desired2, 5)) {
                printf("\nTest case 2 passed.\n\n");
            } else {
                printf("\nTest case 2 failed.\n\n");
            }

        }
        //choice 4, padding spaces to left of string
        if (choice == 4) {
            char test[] = "test";
            char test2[] = "test";
            char desired[] = "  test";
            char desired2[] = "test";
            int n = 6;
            int n2 = 4;
            pad_left(test, n);
            if (compare_arrays(test, desired, 7)) {
                printf("\nTest case 1 passed.\n");
            } else {
                printf("\nTest case 1 failed.\n");
            }
            pad_left(test2, n2);
            if (compare_arrays(test2, desired2, 5)) {
                printf("\nTest case 2 passed.\n\n");
            } else {
                printf("\nTest case 2 failed.\n\n");
            }

        }
        //choice 5, centering string or adding extra space to right side if
        //string is odd.
        if (choice == 5) {
            char test[] = "test";
            char test2[] = "test";
            char desired[] = " test ";
            char desired2[] = " test  ";
            int n = 6;
            int n2 = 7;
            center(test, n);
            if (compare_arrays(test, desired, 7)) {
                printf("\nTest case 1 passed.\n");
            } else {
                printf("\nTest case 1 failed.\n");
            }
            center(test2, n2);
            if (compare_arrays(test2, desired2, 8)) {
                printf("\nTest case 2 passed.\n\n");
            } else {
                printf("\nTest case 2 failed.\n\n");
            }

        }
        //choice 6, checking if string is a palindrome
        if (choice == 6) {
            char test[] = "RADar";
            printf("%d", is_palindrome(test));
            if (is_palindrome(test) == 1) {
                printf("\nTest case 1 passed.\n\n");
            } else {
                printf("\nTest case 1 failed.\n\n");
            }
        }
        //choice 7, truncating string to n characters
        if (choice == 7) {
            char test[] = "test";
            char desired[] = "te";
            char test2[] = "test";
            char desired2[] = "test";
            int n = 2;
            int n2 = 4;
            truncate(test, n);
            if (compare_arrays(test, desired, 3)) {
                printf("\nTest case 1 passed.\n");
            } else {
                printf("\nTest case 1 failed.\n");
            }
            truncate(test2, n2);
            if (compare_arrays(test2, desired2, 5)) {
                printf("\nTest case 2 passed.\n\n");
            } else {
                printf("\nTest case 2 failed.\n\n");
            }
        }
        //choice 8, capitalizing first letter of string
        if (choice == 8) {
            char test[] = "test";
            char desired[] = "Test";
            capitalize(test);
            if (compare_arrays(test, desired, 5)) {
                printf("\nTest case 1 passed.\n\n");
            } else {
                printf("\nTest case 1 failed.\n\n");
            }
        }
        //choice 9, capitalizing first letter of every word in string
        if (choice == 9) {
            char test[] = "test test test";
            char desired[] = "Test Test Test";
            capitalize_words(test);
            if (compare_arrays(test, desired, 15)) {
                printf("\nTest case 1 passed.\n\n");
            } else {
                printf("\nTest case 1 failed.\n\n");
            }
        }
        //choice 10, checking if string is alphabetic
        if (choice == 10) {
            char test[] = "test";
            char test2[] = "1234";
            printf("%d\n", is_alpha(test));
            if (is_alpha(test) == 1) {
                printf("Test case 1 passed.\n");
            } else {
                printf("Test case 1 failed.\n");
            }
            printf("%d\n", is_alpha(test2));
            if (is_alpha(test2) == 0) {
                printf("Test case 2 passed.\n\n");
            } else {
                printf("Test case 2 failed.\n\n");
            }
        }
        //choice 11, reversing string
        if (choice == 11) {
            printf("Enter a string to reverse:\n");
            char test[] = "test";
            char desired[] = "tset";
            reverse(test);
            if (compare_arrays(test, desired, 4)) {
                printf("\nTest case 1 passed.\n\n");
            } else {
                printf("\nTest case 1 failed.\n\n");
            }
        }
        //choice 12, counting occurrences of character in string
        if (choice == 12) {
            char test[] = "test";
            char c = 't';
            printf("%d\n", count_occurrences(test, c));
            if (count_occurrences(test, c) == 2) {
                printf("Test case 1 passed.\n\n");
            } else {
                printf("Test case 1 failed.\n\n");
            }
        }
        //choice 13, deleting all occurrences of character in string
        if (choice == 13) {
            char test[] = "test";
            char c = 't'; //character to delete
            char desired[] = "es";
            delete_char(test, c);
            if (compare_arrays(test, desired, 2)) {
                printf("\nTest case 1 passed.\n\n");
            } else {
                printf("\nTest case 1 failed.\n\n");
            }
        }
        //choice 14, exiting program
        if (choice == 14) {
            printf("Exiting program...\n");
            break;
        }
    }
    return 0;
}

/**
 * This function compares two arrays and returns true if they are identical and
 * false if they are not.
 *
 * *generated: the array generated by the function being tested
 * *desired: the array that the generated array should match
 * size: the size of the array
 */

bool compare_arrays(const char *generated, const char *desired, int size) {
    for (int i = 0; i < size; i++) {
        if (generated[i] != desired[i]) {
            return false; //flag false for non matching array
        }
    }
    return true; //flag true for matching array
}
//end main.c