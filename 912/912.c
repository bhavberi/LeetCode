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

void printHeap(Heap H)
{
    if(isHeapEmpty(H))
    {
        printf("EMPTY HEAP\n");
        return;
    }
    for (int i = 1; i <= H->last; ++i)
        printf("%d ", H->pElements[i]);
    printf("\n");
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    int* arr = (int*)malloc(numsSize*sizeof(int));
    Heap H = initHeap(numsSize+1,-1);
    *returnSize = numsSize;
    for(int i=0;i<numsSize;++i)
        insertHeap(H,nums[i]);
    for(int i=0;i<numsSize;++i)
        arr[i] = extractTop(H);
    return arr;
}
