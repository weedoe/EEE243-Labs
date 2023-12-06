#include <stdio.h>
#include <ctype.h>
int main() {
    char buffer;
    int c = 0;
    FILE *lorem = fopen("lorem.txt", "r");
    FILE *loremupdated = fopen("lorem-updated.txt", "w");
    if (lorem == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    while(fread(&buffer, 1, 1, lorem) == 1) {
        if(c == 20){
            fprintf(loremupdated, "\n");
            c = 0;
        }
        if(islower(buffer)){
            buffer = toupper(buffer);
        }
        fprintf(loremupdated, "%s", &buffer);
        c++;
    }
    fclose(lorem);
    fclose(loremupdated);
}


