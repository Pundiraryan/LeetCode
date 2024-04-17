/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void f(TreeNode* r,string &curr,string &ans){
        if(!r)return;
        if(r->left==nullptr && r->right==nullptr){
            char ch='a'+r->val;
            string ncurr=curr;
            ncurr.push_back(ch);
            reverse(ncurr.begin(),ncurr.end());
            if(ans=="")ans=ncurr;
            else ans=min(ans,ncurr);
            return;
        }
        char ch='a'+r->val;
        string ncurr=curr;
        ncurr.push_back(ch);
        f(r->left,ncurr,ans);
        f(r->right,ncurr,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="",curr="";
        f(root,curr,ans);
        return ans;
    }
};