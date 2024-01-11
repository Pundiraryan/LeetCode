class Solution {
public:
    void dfs(int node,int par,int cd,int &totcost,vector<int>&cost,vector<int>&depth,unordered_map<int,vector<pair<int,int>>>&graph){
        depth[node]=cd;
        for(auto &x:graph[node]){
            int child=x.first,weight=x.second;
            if(child==par)continue;
            cost[child]=cost[node]+weight;
            totcost+=weight;
            dfs(child,node,cd+1,totcost,cost,depth,graph);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>>graph;
        for(auto &x:edges){
            graph[x[0]].push_back({x[1],0});
            graph[x[1]].push_back({x[0],1});
        }
        vector<int>cost(n,0);
        vector<int>ans(n);
        vector<int>depth(n,0);
        int totcost=0;
        dfs(0,-1,0,totcost,cost,depth,graph);
        ans[0]=totcost;
        for(int i=1;i<n;i++){
            int c1=totcost-cost[i];
            int c2=depth[i]-cost[i];
            ans[i]=c1+c2;
        }
        return ans;
        
    }
};