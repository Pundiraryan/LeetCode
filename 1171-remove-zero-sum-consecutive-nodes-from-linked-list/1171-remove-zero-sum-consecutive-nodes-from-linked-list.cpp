/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* f(ListNode* head){
        if(!head)return nullptr;
        ListNode* ptr=head;
        int sum=0;
        while(ptr){
            sum+=(ptr->val);
            if(sum==0){
                head=ptr->next;
                sum=0;
            }
            ptr=ptr->next;
        }
         if(head)head->next=removeZeroSumSublists(head->next);
        return head;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        return f(head);
    }
};