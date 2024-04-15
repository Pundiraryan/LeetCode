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
    int f(TreeNode*r,string str){
        if(!r)return 0;
        if(!r->left && !r->right){
            str+=to_string(r->val);
            return stoi(str);
        }
        string nstr=str;
        nstr+=to_string(r->val);
        return f(r->left,nstr)+f(r->right,nstr);
    }
    int sumNumbers(TreeNode* root) {
        string str="";
        return f(root,str);
    }
};