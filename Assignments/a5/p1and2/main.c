#include <stdio.h>
#define ARRAY_SIZE 10
int smallest;
int *p_smallest;
int add_arrays(const int first_array[], const int second_array[], int result_array[], int array_size);
char *print_array(char *name, int array_size, int array[]);
int main() {
    int first_array[ARRAY_SIZE] = {6, 1, 3, 8, 6, 7, 5, 3, 0, 9};
    int second_array[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int result_array[ARRAY_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int j = 0;
    int i = 20;
    while (j < ARRAY_SIZE) {
        second_array[j] += i - j;
        j++;
    }
    print_array("First array: ", ARRAY_SIZE, first_array);
    print_array("Second array: ", ARRAY_SIZE, second_array);
    print_array("Result array: ", ARRAY_SIZE, result_array);
    add_arrays(first_array, second_array, result_array, ARRAY_SIZE);
    print_array("First array: ", ARRAY_SIZE, first_array);
    print_array("Second array: ", ARRAY_SIZE, second_array);
    print_array("Result array: ", ARRAY_SIZE, result_array);

    printf("%s", "Result array address: ");
    printf("%p\n", &result_array);
    printf("Smallest result value: %d\n", smallest);
    printf("%s", "Smallest value address: ");
    printf("%p\n", p_smallest);
    printf("%s", "Size of an integer on this system: ");
    printf("%lu\n", sizeof(int));


    return 0;
}

int add_arrays(const int first_array[], const int second_array[], int result_array[], int array_size) {
    int i = 0;
    int j = i + 1;
    while (i < array_size) {
        result_array[i] = first_array[i] + second_array[i];
        i++;
    }
    for (i = 0; i < array_size; i++) {
        if (result_array[i] < result_array[j]) {
           smallest = result_array[i];
           p_smallest = &result_array[i];
        }
    }

    return *result_array;
}
char *print_array(char *name, int array_size, int array[]) {
    int i;
    printf("%s", name);
    for (i = 0; i < array_size; i++) {
        printf("%d", array[i]);
        printf("%s", ", ");
    }
    if (i == array_size) {
        printf("%s", "\n\n");
    }
    return 0;
}
