/*
 * This is the code for a singly linked list. Your task is to modify the code to implement
 * a doubly linked list. You must implement the function add_to_end() and print_backwards()
 * with the appropriate parameters and return types.
 *
 * Il s'agit du code d'une liste chaînée. Votre tâche consiste à modifier le code à implémenter
 * une liste doublement liée. Vous devez implémenter la fonction add_to_end() et print_backwards()
 * avec les paramètres et les types de retour appropriés.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Catalog {
    char product[30];
    float price;
    struct Catalog *p_next;
    struct Catalog *p_prev;
} Catalog;

Catalog *create_node(char *product, float price);
void print_forwards(Catalog *p_head);
Catalog *add_to_end(Catalog *p_head, Catalog *p_new);
void print_backwards(Catalog *p_head);
Catalog *add_to_beginning(Catalog *p_head, Catalog *p_new);
void remove_node(Catalog *p_head, Catalog *p_remove);

int main() {

    // Initialize variables
    Catalog *p_head = NULL;
    Catalog *p_new = NULL;
    Catalog *p_p_head = NULL;
    Catalog *p_p_tail = NULL;

    // Create a node and add to beginning
    p_new = create_node("X-Wing Fighter", 10.01);
    p_head = add_to_beginning(p_head, p_new);


    printf("Initial list of one node:\n");
    print_forwards(p_head);

    // Create a node and add to beginning
    p_new = create_node("Millennium Falcon", 435.67);
    p_head = add_to_beginning(p_head, p_new);

    printf("\nPrint list forward after add to beginning\n");
    print_forwards(p_head);

    printf("\nNow backwards\n");
    //call your print_backwards() function
    print_backwards(p_head);
    // Create a node and add to end
    p_new = create_node("Death Star", 3.50);
    //call your add_to_end() function
    add_to_end(p_head, p_new);
    printf("\nPrint list forward after add to end\n");
    print_forwards(p_head);

    printf("\nNow backwards\n");
    //call your print_backwards() function
    print_backwards(p_head);
    return EXIT_SUCCESS;
}

Catalog *create_node(char *product, float price){
    Catalog *p_temp = NULL;
    p_temp = (Catalog *)malloc(sizeof(Catalog));
    strcpy(p_temp->product, product);
    p_temp->price = price;
    return p_temp;
}

void print_forwards(Catalog *p_head){
    Catalog *p_walker = p_head;
    while(p_walker != NULL){
        printf("Product: %-20s -> Price: $%8.2f\n", p_walker->product, p_walker->price);
        p_walker = p_walker->p_next;
    }
}

Catalog *add_to_beginning(Catalog *p_head, Catalog *p_new)
{
    p_new->p_next = p_head;
    p_new->p_prev = NULL;
    if(p_head != NULL){
        p_head->p_prev = p_new;
    }
    p_head = p_new;
    return p_head;
}

Catalog *add_to_end(Catalog *p_head, Catalog *p_new)
{
    Catalog *p_walker = p_head;
    while(p_walker->p_next != NULL){
        p_walker = p_walker->p_next;
    }
    p_walker->p_next = p_new;
    p_new->p_prev = p_walker;
    p_new->p_next = NULL;
    return p_head;
}

void print_backwards(Catalog *p_head)
{
    Catalog *p_walker = p_head;
    while(p_walker != NULL && p_walker->p_next != NULL){
        p_walker = p_walker->p_next;
    }
    while(p_walker != NULL){
        printf("Product: %-20s -> Price: $%8.2f\n", p_walker->product, p_walker->price);
        p_walker = p_walker->p_prev;
    }
}

