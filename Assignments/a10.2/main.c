#include <stdio.h>

int main() {
    char buffer;
    FILE *lorem = fopen("lorem_history.txt", "r");
    FILE *doublespace = fopen("lorem_doublespace.txt", "w");
    while(fread(&buffer, 1, 1, lorem)){
        if(buffer == '\n'){
            fwrite(&buffer, 1, 1, doublespace);
        }
        fwrite(&buffer, 1, 1, doublespace);
    }
    fclose(lorem);
    fclose(doublespace);
    return 0;
}
