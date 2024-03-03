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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*itr=head;
        bool rfn=false;
        for(int i=0;i<=n;i++){
            if(!itr){
                rfn=true;break;
            }
            itr=itr->next;
        }
        if(rfn){
            return head->next;
        }
        ListNode*fptr=head;
        while(itr){
            itr=itr->next;
            fptr=fptr->next;
        }
        if(fptr->next){
            if(fptr->next->next){
                fptr->next=fptr->next->next;
            }else{
                fptr->next=NULL;
            }
        }
        return head;
        
    }
};