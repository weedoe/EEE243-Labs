#include <stdio.h>
void readWord(char *str, FILE *file);

int main() {
    int c = 0;
    char buffer;
    FILE *lorem;
    FILE *loremupdated;
    lorem = fopen("lorem.txt", "r");
    loremupdated = fopen("loremupdated.txt", "w");
    readWord(&buffer, lorem);
    while (buffer != '\0') {
        fwrite(&buffer, sizeof(char), 1, loremupdated);
        readWord(&buffer, lorem);
    }



fclose(lorem);

    return 0;
}

void readWord(char *str, FILE *file) {
    int i = 0;
    char buffer;
    while (fread(&buffer, sizeof(char), 1, file)) {
        if (buffer == ' ' || buffer == '\n') {
            str[i] = '\0';
            return;
        }
        str[i] = buffer;
        i++;
    }
    str[i] = '\0';
}