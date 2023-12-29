class Solution {
public:
    int dp[100005][15];
    int f(int node,int times,int par,vector<vector<int>>&graph,vector<int>&coins,int k){
        if(times>=14)return 0;
        if(dp[node][times]!=-1)return dp[node][times];
        int op1=(coins[node]>>times)-k;
        int op2=coins[node]>>(times+1);
        for(auto &x:graph[node]){
            if(x==par)continue;
            op1+=f(x,times,node,graph,coins,k);
            op2+=f(x,times+1,node,graph,coins,k);
        }
        return dp[node][times]=max(op1,op2);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        memset(dp,-1,sizeof(dp));
        int n=coins.size();
        vector<vector<int>>graph(n);
        for(auto &x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        return f(0,0,-1,graph,coins,k);
    }
};