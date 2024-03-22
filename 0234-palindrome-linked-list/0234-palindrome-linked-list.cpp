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
 ListNode* revl(ListNode* head){
        ListNode* prev=NULL,*curr=head,*temp=NULL;
        while(curr != NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || head->next==nullptr)return true;
        ListNode*s=head,*f=head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode* revh=revl(s);
        while(revh && head){
            if(revh->val!=head->val)return false;
            revh=revh->next;
            head=head->next;
        }
        return true;
    }
};