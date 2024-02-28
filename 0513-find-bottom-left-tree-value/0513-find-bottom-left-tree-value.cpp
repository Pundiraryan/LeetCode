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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>bfs;
        bfs.push(root);
        int lvl=0;
        map<int,vector<int>>fre;
        while(!bfs.empty()){
            int n=bfs.size();
            for(int i=0;i<n;i++){
                TreeNode*curr=bfs.front();
                bfs.pop();
                fre[lvl].push_back(curr->val);
                if(curr->left){
                    bfs.push(curr->left);
                }
                if(curr->right){
                    bfs.push(curr->right);
                }
            }
            lvl++;
        }
        int n=fre.size();
        return fre[n-1][0];
    }
};