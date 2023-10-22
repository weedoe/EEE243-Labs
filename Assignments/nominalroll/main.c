#include <stdio.h>
#include <string.h>

int main() {
    char names[][5] = {"Bob", "Joe", "Jane", "Gill", "John", '\0'};
    char query[0];
    printf("%s\n", "What name are you looking for?");
    scanf("%s", &query[0]);
    int size = sizeof(names) / sizeof(names[0]);
    for (int i = 0; i < size; i++) {
        int compare = strcmp(names[i], query);
        if (compare == 0) {
            printf("%s", query);
            printf("%s", " is in the list");
            return 0;
        }
        if (i == size - 1) {
            printf("%s", query);
            printf("%s", " is not in the list");
            return 0;
        }
    }
}