/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>	/* bool, true, false */
#include "dfs.h"


/* Note: Test cases do not work for some reason.*/

void DFT (node *root){
    stack *topp = NULL; //Top of the stack
	node *temp_node;    //This pointer stores the address of topp->node

    topp = push(topp, root);
	
    while(!isEmpty(topp)) {
		temp_node = top(topp);		//Saving the node of the current stack
        print_node(temp_node);		//Printing the node

		//Popping the printed stack
        topp = pop(topp);

		//If the right child of the node exists, it is pushed to the stack
        if(temp_node->rchild != NULL) {
            topp = push(topp, temp_node->rchild);
            temp_node->rchild->visited = true;      //The node has now been visited
        }
		//Ditto for left child
        if(temp_node->lchild != NULL) {
            topp = push(topp, temp_node->lchild);
            temp_node->lchild->visited = true;
        }
    }
}

node *make_node (int num, node * left, node * right) {
    struct node *element = malloc(sizeof(node));

    element->num = num;
    element->visited = false;
    element->lchild = left;
    element->rchild = right;

    return element;
}

void free_node (node * p) {
    free(p);
}


void print_node (node * p) {
    if (p == NULL)
        printf ("NULL\n");
    else
        printf ("%d ", p->num);
}


void print_tree (node * p, int depth) {
    int i;

    for (i = 0; i < depth; i = i + 1)

        printf (" ");
    printf ("| ");

    if (p == NULL)
        printf ("NULL\n");
    else
        printf ("[%d]\n", p->num);


    if (p->lchild)
        print_tree (p->lchild, depth + 1);

    if (p->rchild)
        print_tree (p->rchild, depth + 1);
}

stack *push (stack * topp, node * node) {
    stack *new_stack = malloc(sizeof(stack));

    new_stack->next = topp;
    new_stack->node = node;

	return new_stack;
}

bool isEmpty (stack * topp) {
    if (topp == NULL) 
        return true;
    else 
        return false;
}

node *top (stack * topp) {
	return topp->node;
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack *topp) {
    stack *temp = topp;

    topp = topp->next;

    free(temp);
	return topp;
}

void print_stack (stack * topp) {
    struct stack *temp = topp;

    while (temp != NULL) {

        print_node (temp->node);
        printf ("\n");

        temp = temp->next;
        }

    printf ("====\n");

    return;
}
