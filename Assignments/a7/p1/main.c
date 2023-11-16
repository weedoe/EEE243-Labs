#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//The type is defined globally
typedef struct productCatalog{
    char product[30]; //Product name
    float price; //Product price
    struct productCatalog *next; //Pointer to the next product
} Catalog;
Catalog *add_to_beginning(Catalog *p_head, Catalog *p_new);
Catalog *search_node(Catalog *p_traverse, char *match);
Catalog *insert_in_order(Catalog *p_head, Catalog *p_new);
Catalog *delete_node(Catalog *p_head, char *del);
void summary(Catalog *p_head);
int main(void) {
    Catalog *p_head = NULL;
    Catalog *p_temp = NULL;
    p_head = (Catalog *)malloc(sizeof(Catalog));
    p_temp = (Catalog *)malloc(sizeof(Catalog));
    strcpy(p_temp->product, "X-Wing Fighter");
    p_temp->price = 10.01f;
    p_temp->next = NULL;
    insert_in_order(p_head, p_temp);
    //printf("Product: %-20s -> Price: $%8.2f\n", p_head->product, p_head->price);
    p_temp = (Catalog *)malloc(sizeof(Catalog));
    strcpy(p_temp->product, "Millennium Falcon");
    p_temp->price = 435.67f;
    p_temp->next = NULL;
    insert_in_order(p_head, p_temp);
    //printf("Product: %-20s -> Price: $%8.2f\n", p_head->product, p_head->price);
    p_temp = (Catalog *)malloc(sizeof(Catalog));
    strcpy(p_temp->product, "Lightsaber");
    p_temp->price = 99.95f;
    p_temp->next = NULL;
    insert_in_order(p_head, p_temp);
    //printf("Product: %-20s -> Price: $%8.2f\n", p_head->product, p_head->price);
    p_temp = (Catalog *)malloc(sizeof(Catalog));
    strcpy(p_temp->product, "Death Star");
    p_temp->price = 5895.32f;
    p_temp->next = NULL;
    insert_in_order(p_head, p_temp);
    //printf("Product: %-20s -> Price: $%8.2f\n", p_head->product, p_head->price);
    p_temp = (Catalog *)malloc(sizeof(Catalog));
    strcpy(p_temp->product, "R2D2");
    p_temp->price = 23.75f;
    p_temp->next = NULL;
    insert_in_order(p_head, p_temp);
//    search_node(p_head, "R2D2");
//    search_node(p_head, "Millennium Falcon");
//    search_node(p_head, "Death Star");
    summary(p_head);
    delete_node(p_head, "Death Star");
    summary(p_head);
    delete_node(p_head, "X-Wing Fighter");
    summary(p_head);
    delete_node(p_head, "R2D2");
    summary(p_head);
    delete_node(p_head, "R2D2");
    summary(p_head);
    delete_node(p_head, "Millennium Falcon");
    summary(p_head);
    delete_node(p_head, "test lol");
    summary(p_head);
    delete_node(p_head, "Lightsaber");
    summary(p_head);

    return EXIT_SUCCESS;
}
Catalog *add_to_beginning(Catalog *p_head, Catalog *p_new){
    p_new->next = p_head;
    return p_new;

}
Catalog *search_node(Catalog *p_traverse, char *match){
    while(p_traverse != NULL){
        if(strcmp(p_traverse->product, match) == 0){
            printf("Product: %-20s -> Price: $%8.2f\n", p_traverse->product, p_traverse->price);
            return p_traverse;
        }
        p_traverse = p_traverse->next;
    }
    printf("%s", match);
    printf(" is not in the list\n");
    return NULL;
}
Catalog *insert_in_order(Catalog *p_head, Catalog *p_new){
    if(p_head == NULL){
        add_to_beginning(p_head, p_new);
    }
    else{
        if(strcmp(p_head->product, p_new->product) > 0){
            add_to_beginning(p_head, p_new);
        }
        else{
            Catalog *p_traverse = p_head;
            while(p_traverse->next != NULL){
                if(strcmp(p_traverse->next->product, p_new->product) > 0){
                    p_new->next = p_traverse->next;
                    p_traverse->next = p_new;
                    return p_head;
                }
                p_traverse = p_traverse->next;
            }
            p_traverse->next = p_new;
            p_new->next = NULL;
        }
    }
    return p_head;
}
void summary(Catalog *p_head){
    float price = 0;
    printf("\n");
    p_head = p_head->next;
    while(p_head!= NULL){
        printf("Product: %-20s -> Price: $%8.2f\n", p_head->product, p_head->price);
        price += p_head->price;
        p_head = p_head->next;
    }
    printf("Total cost is%8.2f\n", price);
}
Catalog *delete_node(Catalog *p_head, char *del) {
    Catalog *p_traverse = p_head;
    Catalog *p_temp = NULL;
    if (strcmp(p_head->product, del) == 0) {
        p_temp = p_head;
        p_head = p_head->next;
        free(p_temp);
        return p_head;
    }
    else if(p_head == NULL){
        return NULL;
    }
    while (p_traverse->next != NULL) {
        if (strcmp(p_traverse->next->product, del) == 0) {
            p_temp = p_traverse->next;
            p_traverse->next = p_traverse->next->next;
            free(p_temp);
            return p_head;
        }
        p_traverse = p_traverse->next;
    }
    return p_head;
}
