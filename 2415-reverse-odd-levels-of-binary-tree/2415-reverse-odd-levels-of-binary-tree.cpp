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
    void f(TreeNode* lc,TreeNode* rc,int cl){
        if(!lc && !rc)return;
        if(cl%2==0){
            swap(lc->val,rc->val);
        }
        f(lc->left,rc->right,cl+1);
        f(lc->right,rc->left,cl+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        f(root->left,root->right,0);
        return root;
    }
};