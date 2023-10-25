#include <stdio.h>
#include <stdlib.h>
void doublearray();
int query();
int* array;
int size = 2;
int iterator = 0;
int main() {
    array = (int*)malloc(size * sizeof(int)); //allocate mem to the array initially
    while (iterator < 5) {
        if (iterator >= size) {
            doublearray();
        }
        array[iterator] = query();
        iterator++;
        printf("%s", "List = [ ");
        for(int i = 0; i < iterator; i++) {
            printf("%d", array[i]);
            printf("%s", " ");
        }
        printf("%s", "]");
        printf("\nThe current size of the array is: %d\n", size);
    }
    free(array); //free up mem for end of program
    return 0;
}
void doublearray() {
    size *= 2;
    array = (int*)realloc(array, size * sizeof(int)); //reallocate mem for double the size
}
int query() {
    int num;
    printf("Enter a new item: ");
    scanf("%d", &num);
    return num;
}