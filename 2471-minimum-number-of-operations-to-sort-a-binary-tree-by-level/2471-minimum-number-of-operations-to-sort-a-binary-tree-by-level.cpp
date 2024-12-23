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
    int f(vector<int>&arr){
        int n=arr.size();
        vector<pair<int,int>>vp(n);
        for(int i=0;i<n;i++)vp[i]={arr[i],i};
        sort(vp.begin(),vp.end());
        vector<int>vis(n,0);
        int ans=0;
        int i=0;
        while(i<n){
            int j=i;
            int cs=0;
            while(!vis[j]){
                cs++;
                vis[j]=1;
                j=vp[j].second;
            }
            ans+=(max(cs-1,0));
            i++;
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        vector<vector<int>>lvls;
        queue<TreeNode*>bfs;
        bfs.push(root);
        while(!bfs.empty()){
            int sz=bfs.size();
            vector<int>clvl;
            while(sz--){
                TreeNode* curr=bfs.front();
                bfs.pop();
                clvl.push_back(curr->val);
                if(curr->left)bfs.push(curr->left);
                if(curr->right)bfs.push(curr->right);
            }
            lvls.push_back(clvl);
        }
        int ans=0;
        for(auto &x:lvls)ans+=f(x);
        return ans;
        
    }
};