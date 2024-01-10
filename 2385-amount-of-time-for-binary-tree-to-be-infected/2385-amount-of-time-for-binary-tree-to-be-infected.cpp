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
    
    void conv(TreeNode*root,unordered_map<int,vector<int>>&graph){
        if(!root)return;
        if(root->left){
            graph[root->val].push_back(root->left->val);
             graph[root->left->val].push_back(root->val);
        }
         if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        conv(root->left,graph);
        conv(root->right,graph);
    }
    int amountOfTime(TreeNode*root,int start) {
        int ans=0;
unordered_map<int,vector<int>>graph;
        conv(root,graph);
        queue<int>bfs;
        unordered_set<int>inf;
        bfs.push(start);
        inf.insert(start);
        while(!bfs.empty()){
            int sz=bfs.size();
            while(sz--){
                int curr=bfs.front();
                bfs.pop();
                for(auto &x:graph[curr]){
                    if(inf.find(x)==inf.end()){
                        inf.insert(x);
                        bfs.push(x);
                    }
                }
            }
            ans++;
        }
        return ans-1;
    }
};