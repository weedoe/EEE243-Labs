#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int global = 10;
const int global_constant = 12;

int main() {
    const float Pi = 3.1416;
    char local_string[] = "TEST";
    char *heap_var = (char*) malloc(sizeof(char));
    int *heap_var2 = (int*) malloc(sizeof(int));
    char *p_char = "World";
    static int static_var = 10;
    printf("%s\n", "Variables are created on the stack, which grows downwards");
    printf("%s", "local constant Pi - A stack address: ");
    printf("%p\n", &Pi);
    printf("%s", "localString - A stack address: ");
    printf("%p\n", &local_string);
    printf("%s", "&heap_var - A stack address: ");
    printf("%p\n", &heap_var);
    printf("%s", "&heap_var2 - A stack address: ");
    printf("%p\n", &heap_var2);
    printf("%s", "&p_char - A stack address: ");
    printf("%p\n\n", &p_char);
    printf("%s\n", "The heap is above the data segment, and grows upwards");
    printf("%s", "heap_var data - A heap address: ");
    printf("%p\n", heap_var);
    printf("%s", "heap_var2 data - A heap address: ");
    printf("%p\n", heap_var2);
    printf("%s\n", "Data stored in the data segment");
    printf("%s", "static_var - A data address: ");
    printf("%p\n", &static_var);
    printf("%s", "global - A data address: ");
    printf("%p\n\n", &global);
    printf("%s\n", "Read-only data stored in the code segment");
    printf("%s\n", "(or sometimes a read-only section created in the data segment)");
    printf("%s", "\"Hello\" - A code segment address:" );
    printf("%p\n", "Hello");
    printf("%s", "*p_char points to \"World\" - A code segment address: ");
    printf("%p\n", p_char);
    printf("%s", "global_constant - A code segment address: ");
    printf("%p\n\n", &global_constant);
    printf("%s\n", "The actual code of the program lives near the bottom of memory");
    printf("%s", "main() - A code segment address: ");
    printf("%p\n", main);


}
