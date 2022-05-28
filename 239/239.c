// DEQUEUE IMPLEMENTATION

#ifndef NODE_H
#define NODE_H

typedef struct Node *Node_ptr;
typedef struct Node Node;
typedef long Element; // ELEMENT TYPE DECLARATION - CHANGE PRINT FNS.

struct Node // Doubly Linked List node.
{
    Element data;
    struct Node *next, *prev;
};

#endif

#ifndef DEQUEUE_H
#define DEQUEUE_H

typedef struct DEQUEUE *Dequeue;
typedef long Size; // SIZE TYPE DECLARATION

struct DEQUEUE // DeQueue Structure
{
    Size size;
    Node_ptr head, tail;
};

int isDequeueEmpty(Dequeue);      // returns 1 if Dequeue is empty and 0 otherwise
void pushFront(Dequeue, Element); // pushes the given element in the given dequeue
Element popFront(Dequeue);        // pops the element at the front of the given dequeue, and returns it
void pushBack(Dequeue, Element);  // pushes the given element in the given dequeue
Element popBack(Dequeue);         // pops the element at the front of the given dequeue, and returns it
Element front(Dequeue);           // Returns the element at the front of the given dequeue
Element back(Dequeue);            // Returns the element at the back of the given dequeue

Dequeue initDequeue();      // Initializes a new dequeue
void emptyDequeue(Dequeue); // Empties the given dequeue

void printDequeue(Dequeue);  // Prlongs the queue front to back
Size sizeofDequeue(Dequeue); // Returns the size of the Dequeue

#endif

// DEQUEUE IMPLENTATIONS -> .C FILE

int isDequeueEmpty(Dequeue dequeue)
{
    return ((dequeue->head == NULL) ? 1 : 0);
}

void pushFront(Dequeue dequeue, Element num)
{
    Node_ptr new_node = (Node_ptr)malloc(sizeof(struct Node));
    assert(new_node != NULL);
    new_node->data = num;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (isDequeueEmpty(dequeue))
        dequeue->head = dequeue->tail = new_node;
    else
    {
        new_node->next = dequeue->head;
        dequeue->head->prev = new_node;
        dequeue->head = new_node;
    }
    ++dequeue->size;
}

void pushBack(Dequeue dequeue, Element num)
{
    Node_ptr new_node = (Node_ptr)malloc(sizeof(struct Node));
    assert(new_node != NULL);
    new_node->data = num;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (isDequeueEmpty(dequeue))
        dequeue->head = dequeue->tail = new_node;
    else
    {
        dequeue->tail->next = new_node;
        new_node->prev = dequeue->tail;
        dequeue->tail = dequeue->tail->next;
    }
    ++dequeue->size;
}

Element popFront(Dequeue dequeue)
{
    if (isDequeueEmpty(dequeue))
    {
        perror("Cannot pop elements from empty queue");
        return -1;
    }
    Element val = dequeue->head->data;
    Node_ptr head = dequeue->head;
    if (dequeue->head == dequeue->tail)
        dequeue->head = dequeue->tail = NULL;
    else
    {
        dequeue->head = dequeue->head->next;
        dequeue->head->prev = NULL;
    }
    --dequeue->size;
    free(head);
    return val;
}

Element popBack(Dequeue dequeue)
{
    if (isDequeueEmpty(dequeue))
    {
        perror("Cannot pop elements from empty queue");
        return -1;
    }
    Element val = dequeue->tail->data;
    Node_ptr tail = dequeue->tail;
    if (dequeue->head == dequeue->tail)
        dequeue->head = dequeue->tail = NULL;
    else
    {
        dequeue->tail = dequeue->tail->prev;
        dequeue->tail->next = NULL;
    }
    --dequeue->size;
    free(tail);
    return val;
}

Element front(Dequeue dequeue)
{
    if (isDequeueEmpty(dequeue))
    {
        printf("Cannot get front element of an empty queue");
        return -1;
    }

    return dequeue->head->data;
}

Element back(Dequeue dequeue)
{
    if (isDequeueEmpty(dequeue))
    {
        printf("Cannot get front element of an empty queue");
        return -1;
    }

    return dequeue->tail->data;
}

Dequeue initDequeue()
{
    Dequeue dequeue = (Dequeue)malloc(sizeof(struct DEQUEUE));
    assert(dequeue != NULL);
    dequeue->head = NULL;
    dequeue->tail = NULL;
    dequeue->size = 0;
    return dequeue;
}

void emptyDequeue(Dequeue queue)
{
    while (queue->size > 0)
        popFront(queue);
}

void printDequeue(Dequeue queue)
{
    Node_ptr curr = queue->head;
    while (curr != NULL)
    {
        printf("%ld ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

Size sizeofDequeue(Dequeue dequeue)
{
    return dequeue->size;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* array, int n, int m, int* returnSize){
    int* arr = (int*)malloc((n-m+1)*sizeof(int));
    *returnSize = n-m+1;
    Dequeue dq = initDequeue();

    for (long i = 0; i < n; i++)
    {

        if (!isDequeueEmpty(dq) && front(dq) == i - m)
            popFront(dq);
        while (!isDequeueEmpty(dq) && array[back(dq)] < array[i])
            popBack(dq);
        
        pushBack(dq, i);

        if (i >= m - 1)
             arr[i-m+1] = array[front(dq)];
    }
    return arr;
}
