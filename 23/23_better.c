#include <limits.h>
#ifndef __HEAP_H
#define __HEAP_H

typedef int HeapElement;
#define MAX INT_MAX
#define MIN INT_MIN

typedef int HeapSize;

typedef struct stHeap
{
    HeapSize last;     // Last Stored Element Index
    HeapSize capacity; // = no. of elements
    HeapElement *pElements;
    int HeapType;
} * Heap;

Heap initHeap(HeapSize capacity, int HeapType); // Heaptype -> +ve for max else min
// Declare a empty heap with its 0th element as -inf/inf for min/max heap

void insertHeap(Heap H, HeapElement n);
int isHeapFull(Heap H);
int isHeapEmpty(Heap H);
HeapElement top(Heap H);
HeapElement extractTop(Heap H);
void printHeap(Heap H);

#endif //__HEAP_H

// IMPLEMENTATIONS -> .c FILE

Heap initHeap(HeapSize capacity, int HeapType)
{
    assert(capacity > 0);

    Heap H = (Heap)malloc(sizeof(struct stHeap));
    assert(H != NULL);

    H->pElements = (HeapElement *)malloc(sizeof(HeapElement) * (capacity + 1));
    assert(H->pElements != NULL);
    H->capacity = capacity;
    H->last = 0;
    H->pElements[0] = (HeapType > 0) ? MAX : MIN;
    H->HeapType = (HeapType > 0) ? 1 : -1;

    return H;
}

void insertHeap(Heap H, HeapElement n)
{
    if (isHeapFull(H))
        return;

    int i = ++H->last;

    if (H->HeapType > 0)
        for (; H->pElements[i / 2] < n; i /= 2)
            H->pElements[i] = H->pElements[i / 2];
    else
        for (; H->pElements[i / 2] > n; i /= 2)
            H->pElements[i] = H->pElements[i / 2];

    H->pElements[i] = n;
}

int isHeapFull(Heap H)
{
    return (H->last == H->capacity) ? 1 : 0;
}

int isHeapEmpty(Heap H)
{
    return (H->last == 0) ? 1 : 0;
}

HeapElement top(Heap H)
{
    if (isHeapEmpty(H))
        return H->pElements[0];
    return H->pElements[1];
}

HeapElement extractTop(Heap H)
{
    if (isHeapEmpty(H))
        return H->pElements[0];
    HeapElement ans = H->pElements[1], last = H->pElements[H->last--];
    HeapSize child, i;

    if (H->HeapType > 0)
    {
        for (i = 1; i * 2 <= H->last; i = child)
        {
            child = 2 * i;
            if ((child != H->last) && (H->pElements[child + 1] > H->pElements[child]))
                child += 1;
            if (last < H->pElements[child])
                H->pElements[i] = H->pElements[child];
            else
                break;
        }
    }
    else
    {
        for (i = 1; i * 2 <= H->last; i = child)
        {
            child = 2 * i;
            if ((child != H->last) && (H->pElements[child + 1] < H->pElements[child]))
                child += 1;
            if (last > H->pElements[child])
                H->pElements[i] = H->pElements[child];
            else
                break;
        }
    }

    H->pElements[i] = last;
    return ans;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize==0)
        return NULL;
    if(listsSize==1)
        return lists[0];
    int count = 0;
    for(int i=0;i<listsSize;++i)
    {
        struct ListNode* j = lists[i];
        while(j!=NULL) {++count;j = j->next;}
    }
    Heap h = initHeap(count+1,-1);
    for(int i=0;i<listsSize;++i)
    {
        struct ListNode* j = lists[i];
        while(j!=NULL) {insertHeap(h,j->val);j = j->next;}
    }
    struct ListNode* ans = NULL;
    struct ListNode* final = ans;
    for(int i=0;i<count;++i)
    {    
        if(ans == NULL)
        {
            ans = malloc(sizeof(struct ListNode));
            ans->val = extractTop(h);
            ans->next = NULL;
            final = ans;
            continue;
        }
        ans->next = malloc(sizeof(struct ListNode));
        ans = ans->next;
        ans->val = extractTop(h);
        ans->next = NULL;
    }
    return final;
}
