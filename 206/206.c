/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* ptr;
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    
    ptr a = head;
    head = reverseList(head->next);
    ptr head1 = head;
    while(head1->next!=NULL) head1= head1->next;
    head1->next = a;
    a->next = NULL;
    return head;   
}
