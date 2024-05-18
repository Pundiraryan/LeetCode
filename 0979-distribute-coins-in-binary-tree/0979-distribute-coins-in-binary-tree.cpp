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
    int f(TreeNode* r,int& ans){
        if(!r)return 0;
        if(r->left==nullptr && r->right==nullptr)return r->val-1;
        int lv=f(r->left,ans),rv=f(r->right,ans);
        ans+=(abs(lv)+abs(rv));
        return lv+rv+(r->val-1);
    }
    int distributeCoins(TreeNode* root) {
        int ans=0;
        f(root,ans);
        return ans;
    }
};