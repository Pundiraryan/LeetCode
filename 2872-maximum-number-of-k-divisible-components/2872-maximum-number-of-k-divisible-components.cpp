class Solution {
public:
    long long ans=0;
    long long dfs(int node,int par,int k,vector<vector<int>>&graph,vector<int>&values){
        long long sum=values[node];
        for(auto &x:graph[node]){
            if(x==par)continue;
            sum+=dfs(x,node,k,graph,values);
        }
        if(sum%k==0){
            ans++;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>graph(n);
        for(auto &x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        dfs(0,-1,k,graph,values);
        return ans;
    }
};