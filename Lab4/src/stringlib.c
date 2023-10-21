//
// Created by William Paterson on 2023-10-18.
//
#include "stringlib.h"
#include <stdio.h>
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
        a[i] = '\n';
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
    while (a[i] == '\0'){
        a[i] = '\n';
        i--;
        if (a[i] == '\0'){
            break;
        }
    }
    printf("%s", a);
}
//end trim_left
//start pad_right
void pad_right(char a[], int n){
    int i = count_chars(a);
    for (int j = i; j <= n; j++){
        a[j] = ' ';
        if (j == n - 1){
            a[j] = '\0';
        }
    }

    printf("%s \n", a);
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
    printf("%s\n", b);
}
