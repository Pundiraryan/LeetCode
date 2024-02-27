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
    int f(TreeNode* r,int &ans){
        if(!r)return 0;
        int lv=f(r->left,ans);
        int rv=f(r->right,ans);
        ans=max({ans,lv,rv,lv+rv});
        return 1+max(lv,rv);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        f(root,ans);
        return ans;
    }
};