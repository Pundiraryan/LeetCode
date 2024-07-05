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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* nn=new ListNode();
        nn->next=head;
        ListNode*pptr=nn,*ptr=head,*nptr=head->next;
        int idx=0;
        vector<int>v;
        while(nptr){
            if(pptr->val!=0){
                if(ptr->val>pptr->val && ptr->val>nptr->val)v.push_back(idx);
                if(ptr->val<pptr->val && ptr->val<nptr->val)v.push_back(idx);
            }
            idx++;
            pptr=ptr;
            ptr=nptr;
            nptr=nptr->next;
        }
        vector<int>ans(2);
        if(v.size()<2)return {-1,-1};
        ans[1]=v[v.size()-1]-v[0];
        ans[0]=1e9;
        for(int i=1;i<v.size();i++)ans[0]=min(ans[0],v[i]-v[i-1]);
        return ans;
    }
};