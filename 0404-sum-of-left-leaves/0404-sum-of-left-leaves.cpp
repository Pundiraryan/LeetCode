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
    int f(TreeNode*r,int s){
        int ans=0;
        if(!r)return 0;
        if(r->left==nullptr && r->right==nullptr){
            if(s==0)return r->val;
            return 0;
        }
        ans+=f(r->left,0);
        ans+=f(r->right,1);
        return ans;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return f(root,-1);
    }
};