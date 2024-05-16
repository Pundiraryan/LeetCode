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
    int f(TreeNode* r){
        if(!r->left && !r->right)return r->val;
        if(r->val==2)return f(r->left)|f(r->right);
        return f(r->left)&f(r->right);
    }
    bool evaluateTree(TreeNode* root) {
        return (bool)f(root);
    }
};