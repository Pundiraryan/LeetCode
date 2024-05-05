/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // ListNode*nn=node;
        ListNode*prev=node;
        while(node->next!=nullptr){
            ListNode*nextnode=node->next;
            swap(nextnode->val,node->val);
            prev=node;
            node=nextnode;
        }
        prev->next=nullptr;
        return;
    }
};