/*
 * Exercise 2: Stack Implementation using Linked List
 * Assignment 7 - IPFCE 2025
 * 
 * Implement all the stack functions declared in include/stack.h
 * The stack should be implemented using a linked list structure.
 * 
 * Functions to implement:
 * - initialize: Create an empty stack
 * - push: Insert an item at the top of the stack
 * - pop: Remove and return the top item
 * - full: Check if stack is full (always false for linked list)
 * - empty: Check if stack is empty
 * - print: Print all items in the stack
 */

#include "stack.h"

/* Create an empty stack */
void initialize(stack *s)
{
    /* pre-condition: true */
    /* post-condition: stack is empty */
    s->head = NULL; //stacken er tom
}

/* Insert item x at the top of stack s */
void push(int x, stack *s)
{
    /* pre-condition: true (linked list can always accept more items) */
    /* post-condition: x is added to top of stack */
    node *new_node =(node *)malloc(sizeof(node)); //allokerer hukommelse til en ny node
    if (new_node == NULL) {
        // Håndter hukommelsesallokeringsfejl
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->data = x; //sætter dataen i noden til x
    new_node->next = s->head; //sætter next pointeren til den nuværende top
    s->head = new_node; //opdaterer stackens head til den nye node
}

/* Return (and remove) the top item of stack s */
int pop(stack *s)
{
  /* pre-condition: stack must not be empty */
  /* post-condition: top item is removed and returned */
    if (empty(s)) {
        fprintf(stderr, "Stack underflow: Attempt to pop from an empty stack\n");
        exit(1); // Exit or handle error as appropriate
    }
    node *temp = s->head; //midlertidig pointer til den nuværende top
    int value = temp->data; //gemmer dataen fra toppen

    s->head = temp->next; //opdaterer head til næste element
    free(temp); //frigør hukommelsen for den gamle top

return value; //returnerer den gemte værdi
}

/* Test whether a stack can accept more pushes */
bool full(stack *s)
{
    /* pre-condition: true */
    /* post-condition: Returns true if stack is full, false otherwise */
    return false;
}

/* Test whether a stack can accept more pops */
bool empty(stack *s)
{
    /* pre-condition: true */
    /* post-condition: returns true if stack is empty, false otherwise */

    return (s->head == NULL); //stacken er tom hvis head er NULL
/* Print the contents of the stack */
void print(stack *s)
{
    if(empty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contents (top to bottom): ");

    node *current = s->head;
    while (current != NULL) {
        printf("%d ", current->data); //printer dataen i den nuværende node
        current = current->next; //går videre til næste node
    }
    printf("\n");
    /* pre-condition: true */
    /* post-condition: prints all items in the stack */
}
