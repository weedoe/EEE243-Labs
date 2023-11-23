/*
 * This program demonstrates the use of doubly-linked list.
 * Complete the functions implementation to remove a node
 *
 * Ce programme démontre l'utilisation d'une liste doublement chaînée.
 * Terminer l'implémentation des fonctions pour enlever un noeud
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Student{
    char name[25];
    unsigned int number;
    struct Student *prev_node;
    struct Student *next_node;
} Node;


Node *create_node(char *name, unsigned int number);
void insert_node(Node **p_p_head, Node **p_p_tail, Node *p_new);
void remove_node(Node **p_p_head, Node **p_p_tail, unsigned int number);
void print(Node *p_head);
void print_reverse(Node *p_tail);


int main () {

    Node *head = NULL;
    Node *tail = NULL;

    Node *john = create_node("John", 29078);
    Node *paul = create_node("Paul", 29036);
    Node *george = create_node("George", 29053);
    Node *ringo = create_node("Ringo", 29007);

    insert_node(&head, &tail, john);
    print(head);
    insert_node(&head, &tail, paul);
    print(head);
    insert_node(&head, &tail, george);
    print(head);
    insert_node(&head, &tail, ringo);
    print(head);
    print_reverse(tail);

	//Remove the Nodes
	//Requires your implementation of the remove_node() fonction
    remove_node(&head, &tail, 29053);
    print(head);
    remove_node(&head, &tail, 29007);
    print(head);
    print_reverse(tail);
    remove_node(&head, &tail, 29078);
    print(head);
    print_reverse(tail);
    remove_node(&head, &tail, 29036);
    /*print(head);
    print_reverse(tail);*/


    return 0;
}


/*
 * Creates and allocates memory for a node.
 *
 * name: the name of the student
 * number: the college number of the student
 */
Node *create_node(char *name, unsigned int number) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->number = number;
    new_node->prev_node = NULL;
    new_node->next_node = NULL;
    return new_node;
}


/*
 * Insert the node in the list ordered by college number.
 *
 * p_p_head: pointer of pointer to the head of the list
 * p_p_tail: pointer of pointer to the tail of the list
 * p_new: pointer to the node to be inserted into the list
 */
void insert_node(Node **p_p_head, Node **p_p_tail, Node *p_new) {
    Node *p_traverse;

    // Special case - empty list
    if (*p_p_head == NULL) {
        *p_p_head = p_new;
        *p_p_tail = p_new;
        return;
    }

    // Special case - node inserted at the head
    if ((*p_p_head)->number > p_new->number){
        p_new->next_node = *p_p_head;
        *p_p_head = p_new;
        p_new->next_node->prev_node = p_new;
        return;
    }

    // Other case - node inserted somewhere in the list
    // Insert the new node after p_traverse
    p_traverse = *p_p_head;
    while (p_traverse->next_node != NULL &&
           p_traverse->next_node->number < p_new->number) {
        p_traverse = p_traverse->next_node;
    }
    // If the node is inserted in the middle of the list
    if (p_traverse->next_node != NULL) {
        p_new->next_node = p_traverse->next_node;
        p_traverse->next_node = p_new;
        p_new->prev_node = p_traverse;
        p_new->next_node->prev_node = p_new;
    // The node is inserted at the end of the list
    } else {
        p_traverse->next_node = p_new;
        p_new->next_node = NULL;
        p_new->prev_node = p_traverse;
        *p_p_tail = p_new;
    }
}


/*
 * Removes a node from the list.
 *
 * p_p_head: pointer of pointer to the head of the list
 * p_p_tail: pointer of pointer to the tail of the list
 * number: college number of the node to be removed
 */
void remove_node(Node **p_p_head, Node **p_p_tail, unsigned int number) {
    Node *p_pred;
    Node *p_traverse = *p_p_head;

    // Special case – empty list
    if (p_traverse == NULL) {
        return;
    }

    // Special case - node to remove is the head and the list
    // has a single node
    if (p_traverse->number == number && *p_p_head == *p_p_tail) {
        while(p_traverse != NULL){
            free(p_traverse);
            p_traverse = NULL;
        }

        return;
    }

    // Special case - node to remove is the head and the list
    // has more than one node
    if (p_traverse->number == number) {
        *p_p_head = p_traverse->next_node;
        (*p_p_head)->prev_node = NULL;
        return;
    }

    // Other case - node to remove is somewhere in the list
    while (p_traverse != NULL && p_traverse->number != number) {
        p_pred = p_traverse;
        p_traverse = p_traverse->next_node;
    }
    // The node was found...
    if (p_traverse != NULL) {
        // ...at the end of the list
        if (p_traverse == *p_p_tail) {
            p_pred->next_node = NULL;
            *p_p_tail = p_pred;
            free(p_traverse);
            p_traverse = NULL;
			
        // ...somewhere in the middle of the list
        } else {
            p_pred->next_node = p_traverse->next_node;
            p_traverse->next_node->prev_node = p_pred;
            free(p_traverse);
            p_traverse = NULL;

        }
    }
	
}


/*
 * Prints the list in numerical order.
 *
 * p_head: pointer to the head of the list
 */
void print(Node *p_head) {
    Node *p_traverse = p_head;

    if (p_traverse == NULL) {
        return;
    }

    while (p_traverse != NULL) {
        printf("%d %s -> ", p_traverse->number, p_traverse->name);
        p_traverse = p_traverse->next_node;
    }
    printf("\b\b\b   \n");  // overwrite the last arrow with spaces
}


/*
 * Prints the list in reverse numerical order.
 *
 * p_tail: pointer to the tail of the list
 */
void print_reverse(Node *p_tail) {
    Node *p_traverse = p_tail;

    if (p_traverse == NULL) {
        return;
    }

    while (p_traverse != NULL) {
        printf("%d %s <- ", p_traverse->number, p_traverse->name);
        p_traverse = p_traverse->prev_node;
    }
    printf("\b\b\b   \n");  // overwrite the last arrow with spaces
}