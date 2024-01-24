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
    void f(TreeNode*r,int mask,int &ans){
        if(!r)return ;
        int nm=mask^(1<<(r->val));   
        if(!r->left && !r->right){
            if((nm&(nm-1))==0)ans++;
            return;
        }
           
        f(r->left,nm,ans);
        f(r->right,nm,ans);
    } 
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
         f(root,0,ans);
        return ans;
    }
};