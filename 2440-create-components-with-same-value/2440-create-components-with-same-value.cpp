class Solution {
public:
    int dfs(int src,int par,int tar,vector<int>&nums,vector<vector<int>>&graph){
        int cs=nums[src];
        for(auto &x:graph[src]){
            if(x==par)continue;
            cs+=dfs(x,src,tar,nums,graph);
        }
        if(cs==tar)return 0;
        return cs;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int sum = 0;
        for(auto &x:nums)sum+=x;
        vector<vector<int>>graph(n);
        for(auto &x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        int ans=0;
        for(int parts = 1;parts <= n;parts++){
            if(sum%parts != 0) continue;
            if(dfs(0,-1,sum/parts,nums,graph) !=0) continue;
            ans = max(ans,parts-1);
        }
        return ans;
    }
};