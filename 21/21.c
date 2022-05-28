/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* ptr;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    ptr head = NULL;
    ptr ans = NULL;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val <= list2->val)
        {
            if(head == NULL)
            {
                head = list1;
                ans = list1;
            }
            else
            {
                head->next = list1;
                // if(list1->next)
                head = head->next;
            }
            list1 = list1->next;
        }
        else
        {
            if(head == NULL)
            {
                head = list2;
                ans = list2;
            }
            else
            {
                head->next = list2;
                // if(list2->next)
                head = head->next;
            }
            list2 = list2->next;
        }
        // if (head !=NULL)
        // printf("%d",head->val);
    }
    while(list1 != NULL)
    {
        // if (head !=NULL)
        //     printf("%d",head->val);
        if(head == NULL)
        {
            head = list1;
            ans = list1;
        }
        else
        {
            head->next = list1;
            head = head->next;
        }
        list1 = list1->next;
    }
    
    while(list2 != NULL)
    {
        // if (head !=NULL)
        //     printf("%d",head->val);
        if(head == NULL)
        {
            head = list2;
            ans = list2;
        }
        else
        {
            head->next = list2;
            head = head->next;
        }
        list2 = list2->next;
    }
    // printf("\n");
    return ans;
}
