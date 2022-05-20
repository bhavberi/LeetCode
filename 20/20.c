#include <assert.h>
#include <string.h>

#ifndef NODE_H
#define NODE_H

typedef struct Node *Node_ptr;
typedef struct Node Node;
typedef char Element; // ELEMENT TYPE DECLARATION - CHANGE PRINT FNS.

struct Node // Doubly Linked List node.
{
    Element data;
    struct Node *next, *prev;
};

#endif

#ifndef STACK_H
#define STACK_H

typedef struct STACK *Stack;
typedef long Size; // SIZE TYPE DECLARATION

struct STACK // Stack Structure
{
    Size size;
    Node_ptr head, tail;
};

int isStackEmpty(Stack);        // returns 1 if stack is empty and 0 otherwise
void pushStack(Stack, Element); // pushes the given element in the given stack
Element popStack(Stack);        // pops the element at the top of the given stack, and returns it
Element topStack(Stack);        // Returns the element at the top of the given stack

Stack initStack();      // Initializes a new stack
void emptyStack(Stack); // Empties the given stack

Size sizeofStack(Stack);        // Returns the size of the Stack

#endif

// IMPLEMENTATIONS -> .C FILE
int isStackEmpty(Stack stack)
{
    return ((stack->head == NULL) ? 1 : 0);
}

void pushStack(Stack stack, Element num)
{
    Node_ptr new_node = (Node_ptr)malloc(sizeof(struct Node));
    assert(new_node != NULL);
    new_node->data = num;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (isStackEmpty(stack))
        stack->head = stack->tail = new_node;
    else
    {
        stack->tail->next = new_node;
        new_node->prev = stack->tail;
        stack->tail = stack->tail->next;
    }
    ++stack->size;
}

Element popStack(Stack stack)
{
    if (isStackEmpty(stack))
    {
        perror("Cannot pop elements from empty stack");
        return -1;
    }
    Element val = stack->tail->data;
    Node_ptr tail = stack->tail;
    if (stack->head == stack->tail)
        stack->head = stack->tail = NULL;
    else
    {
        stack->tail = stack->tail->prev;
        stack->tail->next = NULL;
    }
    --stack->size;
    free(tail);
    return val;
}

Element topStack(Stack stack)
{
    if (isStackEmpty(stack))
    {
        perror("Cannot get top element of an empty stack");
        return -1;
    }
    return stack->tail->data;
}

Stack initStack()
{
    Stack stack = (Stack)malloc(sizeof(struct STACK));
    assert(stack != NULL);
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
    return stack;
}

void emptyStack(Stack stack)
{
    while (stack->size > 0)
        popStack(stack);
}


Size sizeofStack(Stack stack)
{
    return stack->size;
}

bool isValid(char * s){
    int l = strlen(s);
    Stack st = initStack();
    for(int i=0;i<l;++i)
    {
        if(s[i] == ')')
        {
            if(!sizeofStack(st))
                return false;
            char c = popStack(st);
            if(c!='(')
                return false;
        }
        else if(s[i] == ']')
        {
            if(!sizeofStack(st))
                return false;
            char c = popStack(st);
            if(c!='[')
                return false;
        }
        else if(s[i] == '}')
        {
            if(!sizeofStack(st))
                return false;
            char c = popStack(st);
            if(c!='{')
                return false;
        }
        else
        {
            pushStack(st,s[i]);
        }
    }
    if(sizeofStack(st))
    {
        return false;
    }
    return true;
}
