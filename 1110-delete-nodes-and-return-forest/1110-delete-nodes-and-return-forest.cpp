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
    TreeNode* f(TreeNode*r,unordered_set<int>&st,vector<TreeNode*>&res){
        if(!r)return nullptr;
        TreeNode*lr=f(r->left,st,res);
        TreeNode*rr=f(r->right,st,res);
        r->left=lr;
        r->right=rr;
        if(st.find(r->val)!=st.end()){
            if(lr)res.push_back(lr);
            if(rr)res.push_back(rr);
            delete r;
            return nullptr;
        }
        return r;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
       vector<TreeNode*>ans;
        unordered_set<int>st;
        for(auto &x:to_delete)st.insert(x);
        TreeNode*rv=f(root,st,ans);
        if(rv)ans.push_back(rv);
        return ans;
    }
};