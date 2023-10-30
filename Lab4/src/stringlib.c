/**
 * C file to make a library for all of the string functions prototyped in
 * stringlib.h. This file contains the functions that are used to manipulate
 * strings in main.c.
 *
 * Author: OCdt Paterson 30648
 * Version: October 31st 2023
 */
#include "stringlib.h" //including prototype functions
#include <stdio.h>
#include <ctype.h>

/**
 * This function counts the number of characters in a string and returns the
 * number of characters.
 *
 * a[]: the string to be counted
 * return: the number of characters in the string
 */
//start count_chars
int count_chars(char a[]) {
    int i = 0;
    while (a[i] != '\0') {
        i++;
    }
    return i;
}

//end count_chars

/**
 * This function removes any space characters from the right end of a string.
 *
 * a[]: the string to be trimmed
 */

//start trim_right
void trim_right(char a[]) {
    int i = count_chars(a);
    while (a[i] == '\0') {
        a[i - 1] = '\n';
        i++;
        if (a[i] == '\0') {
            break;
        }
    }
    printf("%s", a);
}

//end trim_right

/**
 * This function removes any space characters from the left end of a string.
 *
 * a[]: the string to be trimmed
 */

//start trim_left
void trim_left(char a[]) {
    int i = count_chars(a);
    for (int j = 0; j < i; j++) {
        if (a[j] == ' ') {
            j++;
            if (a[j] != ' ') {
                for (int k = 0; k < i; k++) {
                    a[k] = a[j];
                    j++;
                }
            }
        }
        printf("%s", a);
    }
}

//end trim_left

/**
 * This function adds extra spaces at the right end of a string to make it n
 * characters long. If the string is already n characters or longer, does
 * nothing.
 *
 * a[]: the string to be padded
 * n: the number of characters the string should be
 */

//start pad_right
void pad_right(char a[], int n) {
    int i = count_chars(a);
    for (int j = i; j < n; j++) {
        if (i == n) {
            printf("The string is already this length, exiting.");
            break;
        }
        a[j] = ' ';
        if (count_chars(a) - 1 == n) {
            a[j] = '\0';
        }
    }

    printf("%s", a);
}

//end pad_right

/**
 * This function adds extra spaces at the left end of a string to make it n
 * characters long. If the string is already n characters or longer, does
 * nothing.
 *
 * a[]: the string to be padded
 * n: the number of characters the string should be
 */

//start pad_left4
void pad_left(char a[], int n) {
    int length = count_chars(a);
    int spaces = n - length;
    char b[n + 1]; // +1 for the null terminator
    int i;
    for (i = 0; i < spaces; i++) {
        b[i] = ' ';
    }
    for (int j = 0; j < length; j++) {
        b[i] = a[j];
        i++;
    }
    b[n] = '\0';
    for (int k = 0; k < sizeof(b); k++) {
        a[k] = b[k];
    }
    printf("%s", a);
}

//end pad_left

/**
 * This function centers a string by adding spaces to the left and right to
 * bring it to the length n. If the string is already of the specified length
 * or longer, does not change the string. If an odd number of spaces have to
 * be added, puts the extra blank on the right.
 *
 * a[]: the string to be centered
 * n: the number of characters the string should be
 */

//start center
void center(char a[], int n) {
    int length = count_chars(a);
    int spaces = n - length;
    int center = spaces / 2;
    char b[n + 1]; // +1 for the null terminator
    int i;
    for (i = 0; i < center; i++) {
        if (center % 2 == 1) {
            b[i] = ' ';
        } else {
            b[i] = ' ';
            i++;
        }
    }
    for (int j = 0; j < length; j++) {
        b[i] = a[j];
        i++;
    }
    for (int k = i; k <= n; k++) {
        b[k] = ' ';
    }
    b[n] = '\0';
    for (int k = 0; k < sizeof(b); k++) {
        a[k] = b[k];
    }
    printf("%s", a);
}
//end center

/**
 * This function returns true if a string is a palindrome, false otherwise.
 *
 * a[]: the string to be checked
 * return: true if the string is a palindrome, false otherwise
 */

//start palindrome
bool is_palindrome(char a[]) {
    int length = count_chars(a);
    for (int i = 0; i < length; i++) {
        a[i] = tolower(a[i]); // NOLINT(*-narrowing-conversions)
    }
    int i = 0;
    int j = length - 1;
    while (i < j) {
        if (a[i] != a[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

//end palindrome

/**
 * This function returns true if a string is a palindrome, false otherwise.
 *
 * a[]: the string to be checked
 * return: true if the string is a palindrome, false otherwise
 */

//start truncate
void truncate(char a[], int n) {
    int length = count_chars(a);
    if (length > n) {
        a[n] = '\0';
    }
    printf("%s", a);
}

//end truncate

/**
 * This function returns true if a string is a palindrome, false otherwise.
 *
 * a[]: the string to be checked
 * return: true if the string is a palindrome, false otherwise
 */

//start capitalize
void capitalize(char a[]) {
    int length = count_chars(a);
    for (int i = 0; i < length; i++) {
        a[i] = tolower(a[i]); // NOLINT(*-narrowing-conversions)
    }
    a[0] = toupper(a[0]); // NOLINT(*-narrowing-conversions)
    printf("%s", a);
}

//end capitalize

/**
 * This function returns true if a string is a palindrome, false otherwise.
 *
 * a[]: the string to be checked
 * return: true if the string is a palindrome, false otherwise
 */

//start capitalize_words
void capitalize_words(char a[]) {
    int length = count_chars(a);
    a[0] = toupper(a[0]); // NOLINT(*-narrowing-conversions)
    for (int i = 0; i < length; i++) {
        if (a[i] == ' ') {
            a[i + 1] = toupper(a[i + 1]); // NOLINT(*-narrowing-conversions)
        }
    }
    printf("%s", a);
}
//end capitalize_words

/**
 * This function returns true if a string is a palindrome, false otherwise.
 *
 * a[]: the string to be checked
 * return: true if the string is a palindrome, false otherwise
 */

//start is_alpha
bool is_alpha(char a[]) {
    int length = count_chars(a);
    for (int i = 0; i < length; i++) {
        if (isalpha(a[i]) == 0) {
            return false;
        }
    }
    return true;
}

//end is_alpha

/**
 * This function returns true if a string is a palindrome, false otherwise.
 *
 * a[]: the string to be checked
 * return: true if the string is a palindrome, false otherwise
 */

//start reverse
void reverse(char a[]) {
    int length = count_chars(a);
    char b[length + 1];
    int i = 0;
    int j = length - 1;
    while (i < length) {
        b[i] = a[j];
        i++;
        j--;
    }
    b[length] = '\0';
    for (int k = 0; k < sizeof(b); k++) {
        a[k] = b[k];
    }
    printf("%s", a);
}

//end reverse

/**
 * This function returns true if a string is a palindrome, false otherwise.
 *
 * a[]: the string to be checked
 * return: true if the string is a palindrome, false otherwise
 */

//start count_occurrences
int count_occurrences(char a[], char c) {
    int length = count_chars(a);
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (a[i] == c) {
            count++;
        }
    }
    return count;
}

//end count_occurrences

/**
 * This function returns true if a string is a palindrome, false otherwise.
 *
 * a[]: the string to be checked
 * return: true if the string is a palindrome, false otherwise
 */

//start delete_char
void delete_char(char a[], char c) {
    int length = count_chars(a);
    int i = 0;
    int j = 0;
    while (i < length) {
        if (a[i] != c) {
            a[j] = a[i];
            j++;
        }
        i++;
    }
    a[j] = '\0';
    printf("%s", a);
}
//end delete_char
//end stringlib.c