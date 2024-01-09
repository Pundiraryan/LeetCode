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
    void trav(TreeNode *r,vector<int>&v){
        if(!r)return;
        trav(r->left,v);
        if(!r->right && !r->left){
            v.push_back(r->val);
        }
        trav(r->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>rv1,rv2;
        trav(root1,rv1);
        trav(root2,rv2);
        if(rv1.size()!=rv2.size())return false;
        for(int i=0;i<rv1.size();i++){
            if(rv1[i]!=rv2[i])return false;
        }
        return true;
    }
};