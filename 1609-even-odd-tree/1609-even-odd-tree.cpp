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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>bfs;
        bfs.push(root);
        int lvl=0;
        map<int,vector<int>>fre;
        while(!bfs.empty()){
            int sz=bfs.size();
            for(int i=0;i<sz;i++){
                TreeNode* curr=bfs.front();
                bfs.pop();
                fre[lvl].push_back(curr->val);
                if(curr->left)bfs.push(curr->left);
                if(curr->right)bfs.push(curr->right);
            }
            lvl++;
        }
        for(auto &x:fre){
            int val=x.first;
            vector<int>values=x.second;
            if(val%2==0){
                int curr=values[0];
                if(curr%2==0)return false;
                for(int i=1;i<values.size();i++){
                    if(values[i]%2==0 || values[i]<=curr)return false;
                    curr=values[i];
                }
            }else{
                int curr=values[0];
                if(curr%2==1)return false;
                for(int i=1;i<values.size();i++){
                    if(values[i]%2==1 || values[i]>=curr)return false;
                    curr=values[i];
                }
            }
        }
        return true;
    }
};