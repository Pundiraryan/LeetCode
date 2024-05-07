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
    ListNode* doubleIt(ListNode* head) {
        ListNode* rh=f(head,nullptr);
        ListNode*oh=rh;
        ListNode*pn=rh;
        int carry=0;
        while(rh){
            int currval=2*(rh->val);
            currval+=carry;
            carry=(currval)/10;
            rh->val=(currval)%10;
            pn=rh;
            rh=rh->next;
        }
        if(carry){
            pn->next=new ListNode(carry);
        }
        return f(oh,nullptr);
    }
};