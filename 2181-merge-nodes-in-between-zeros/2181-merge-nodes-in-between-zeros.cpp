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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*ptr=head->next;
        ListNode* dummy=new ListNode();
        ListNode* cptr=dummy,*dn=dummy;
        int cv=0;
        while(ptr){
            if(ptr->val){
                cv+=ptr->val;
            }else{
                // cout<<cv<<" -- \n";
                ListNode* nn=new ListNode(cv);
                cptr->next=nn;
                cptr=cptr->next;
                cv=0;
            }
            ptr=ptr->next;
        }
        return dn->next;
    }
};