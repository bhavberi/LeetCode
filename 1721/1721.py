/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* ptr;
struct ListNode* swapNodes(struct ListNode* head, int k){
    ptr arr[100000];
    long count = 0;
    while(head!=NULL)
    {
        arr[count++] = head;
        head = head->next;
    }
    int temp = arr[k-1]->val;
    arr[k-1]->val = arr[count - k]->val;
    arr[count - k]->val = temp;
    return arr[0];
}
