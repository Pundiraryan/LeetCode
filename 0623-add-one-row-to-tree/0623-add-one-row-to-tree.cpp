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
    void f(TreeNode* rv,int d,int val){
        if(d<0 ||!rv)return;
        if(d==0){
            TreeNode*ol=rv->left;
            TreeNode*ort=rv->right;
            TreeNode*nl=new TreeNode(val);
            TreeNode*nr=new TreeNode(val);
            rv->left=nl;rv->right=nr;
            nl->left=ol;nr->right=ort;
            return;
        }
        f(rv->left,d-1,val);
        f(rv->right,d-1,val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode*r=new TreeNode(val);
            r->left=root;
            return r;
        }
        f(root,depth-2,val);
        return root;
        
    }
};