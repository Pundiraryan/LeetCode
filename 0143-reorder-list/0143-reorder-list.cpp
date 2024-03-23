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
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr)return;
        stack<ListNode*>st;
        ListNode*ptr=head;
        int len=0;
        while(ptr){
            st.push(ptr);
            cout<<ptr->val<<endl;
            ptr=ptr->next;
            len++;
        }
        cout<<" -- "<<len<<endl;
        ListNode*curr=head;
        for(int i=0;i<len/2;i++){
            ListNode*bk=st.top();
            st.pop();
            bk->next=curr->next;
            curr->next=bk;
            curr=curr->next->next;
        }
        curr->next=nullptr;
    }
};