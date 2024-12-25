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
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        vector<int>ans;
        queue<TreeNode*>bfs;
        bfs.push(root);
        while(!bfs.empty()){
            int sz=bfs.size();
            priority_queue<int>pq;
            while(sz--){
                auto curr=bfs.front();
                bfs.pop();
                pq.push(curr->val);
                if(curr->left)bfs.push(curr->left);
                if(curr->right)bfs.push(curr->right);
            }
            ans.push_back(pq.top());
        }
        return ans;
    }
};