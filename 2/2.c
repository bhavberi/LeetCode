/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode *Node_ptr;
typedef struct ListNode Node;

Node_ptr createNode(int elem)
{
    Node_ptr p = (Node_ptr)malloc(sizeof(Node));
    assert(p != NULL);

    p->val = elem;
    p->next = NULL;
    return p;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    Node_ptr head = createNode(l1->val + l2->val);
    Node_ptr p = head;
    int sum = 0, carry = 0;
    if (head->val > 9)
    {
        carry = 1;
        head->val -= 10;
    }
    l1 = l1->next;
    l2 = l2->next;
    while (l1 != NULL || l2 != NULL)
    {
        sum = carry;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        if (sum > 9)
        {
            carry = 1;
            sum -= 10;
        }
        else
            carry = 0;

        p->next = createNode(sum);
        p = p->next;
    }
    if (carry)
        p->next = createNode(carry);
    return head;
}
