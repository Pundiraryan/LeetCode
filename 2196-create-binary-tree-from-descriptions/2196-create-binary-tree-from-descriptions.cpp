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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*>fre;
        for(auto &x:descriptions){
             if(fre.count(x[0])==0){
                TreeNode* par = new TreeNode(x[0]);
                fre[x[0]] = par;
            }
            if(fre.count(x[1])==0){
                TreeNode* child = new TreeNode(x[1]);
                fre[x[1]] = child;
            }
            if(x[2]==1) fre[x[0]]->left = fre[x[1]];              
            else fre[x[0]]->right = fre[x[1]];
        }
        unordered_map<int,int>mp;
        for(auto &x:descriptions){
            mp[x[1]]++;
        }
        for(auto &x:descriptions){
            if(mp[x[0]]==0)return fre[x[0]];
            if(mp[x[1]]==0)return fre[x[1]];
        }
        return nullptr;

    }
};