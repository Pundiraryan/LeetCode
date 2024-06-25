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
    int val=0;
    void f(TreeNode*r){
        if(!r)return ;
        f(r->right);
        val+=r->val;
        r->val=val;
        f(r->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        f(root);
        return root;
    }
};