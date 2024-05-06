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
    ListNode* revl(ListNode*c,ListNode*p){
        if(!c)return p;
        ListNode*n =c->next;
        c->next=p;
        return revl(n,c);
    }
    ListNode* removeNodes(ListNode* head) {
        if(!head->next)return head;
        ListNode*rh=revl(head,nullptr);
        ListNode*ptr1=rh,*ptr2=rh->next;
        ListNode*pptr=nullptr;
        while(ptr2){
            if(ptr1->val > ptr2->val){
                ptr1->next=ptr2->next;
                ptr2=ptr1->next;
            }else{
                if(!pptr)pptr=ptr1;
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
        }
        if(!pptr)return new ListNode(rh->val);
        return revl(pptr,nullptr);
    }
};