//
// Created by William Paterson on 2023-10-18.
//
#include "stringlib.h"
#include <stdio.h>
#include <ctype.h>
//count_chars
int count_chars(char a[]){
    int i = 0;
    while (a[i] != '\0') {
        i++;
    }
    return i;
}
//end count_chars
//start trim_right
void trim_right(char a[]){
    int i = count_chars(a);
    while (a[i] == '\0'){
        a[i-1] = '\n';
        i++;
        if (a[i] == '\0'){
            break;
        }
    }
    printf("%s", a);
}
//end trim_right
//start trim_left
void trim_left(char a[]){
    int i = count_chars(a);
    for(int j = 0; j < i; j++){
        if (a[j] == ' '){
            j++;
            if (a[j] != ' '){
                for(int k = 0; k < i; k++){
                a[k] = a[j];
                j++;
                }
            }
        }
        printf("%s", a);
    }
}
//end trim_left
//start pad_right
void pad_right(char a[], int n){
    int i = count_chars(a);
    for (int j = i; j < n; j++){
        if (i == n){
            printf("The string is already this length, exiting.");
            break;
        }
        a[j] = ' ';
        if (count_chars(a) - 1 == n){
            a[j] = '\0';
        }
    }

    printf("%s", a);
    }
//end pad_right
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
    for(int k = 0; k < sizeof(b); k++){
        a[k] = b[k];
    }
    printf("%s", a);
}
//end pad_left
//start center
void center(char a[], int n){
    int length = count_chars(a);
    int spaces = n - length;
    int center = spaces / 2;
    char b[n + 1]; // +1 for the null terminator
    int i;
    for (i = 0; i < center; i++) {
        if (center % 2 == 1){
            b[i] = ' ';
        }
        else{
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
    for(int k = 0; k < sizeof(b); k++){
        a[k] = b[k];
    }
    printf("%s", a);
}
//end center
//start palindrome
bool is_palindrome(char a[]){
    int length = count_chars(a);
    for (int i = 0; i < length; i++) {
        a[i] = tolower(a[i]); // NOLINT(*-narrowing-conversions)
    }
    int i = 0;
    int j = length - 1;
    while (i < j){
        if (a[i] != a[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
//end palindrome
//start truncate
void truncate(char a[], int n){
    int length = count_chars(a);
    if (length > n){
        a[n] = '\0';
    }
    printf("%s", a);
}
//end truncate
//start capitalize
void capitalize(char a[]){
    int length = count_chars(a);
    for (int i = 0; i < length; i++) {
        a[i] = tolower(a[i]); // NOLINT(*-narrowing-conversions)
    }
    a[0] = toupper(a[0]); // NOLINT(*-narrowing-conversions)
    printf("%s", a);
}
//end capitalize
//start capitalize_words
void capitalize_words(char a[]){
    int length = count_chars(a);
    a[0] = toupper(a[0]); // NOLINT(*-narrowing-conversions)
    for (int i = 0; i < length; i++){
        if (a[i] == ' '){
            a[i + 1] = toupper(a[i + 1]); // NOLINT(*-narrowing-conversions)
        }
    }
    printf("%s", a);
}