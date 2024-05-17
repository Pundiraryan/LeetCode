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
    TreeNode* f(TreeNode*r,int t){
        if(!r)return nullptr;
        if(r->left==nullptr && r->right==nullptr){
            if(r->val==t)return nullptr;
            return r;
        }
        r->left=f(r->left,t);
        r->right=f(r->right,t);
       if(r->left==nullptr && r->right==nullptr){
            if(r->val==t)return nullptr;
            return r;
        }
        return r;
        
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return f(root,target);
    }
};