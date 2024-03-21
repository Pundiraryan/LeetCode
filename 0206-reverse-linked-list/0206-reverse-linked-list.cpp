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
    ListNode* f(ListNode*c,ListNode*p){
        if(!c)return p;
        ListNode*n =c->next;
        c->next=p;
        return f(n,c);
    }
    ListNode* reverseList(ListNode* head) {
        return f(head,nullptr);
    }
};