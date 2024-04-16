class Solution {
public:
    int precomp(int src,int par,vector<int>&sz,vector<vector<int>>&graph){
        int res=1;
        for(auto &x:graph[src]){
            if(x==par)continue;
            res+=precomp(x,src,sz,graph);
        }
        return sz[src]=res;
    }
    void run(int src,int par,int dis,vector<int>&ans,vector<vector<int>>&graph){
        for(auto &x:graph[src]){
            if(x==par)continue;
            run(x,src,dis+1,ans,graph);
        }
        ans[0]+=dis;
        return;
    }
    void dfs(int src,int par,vector<int>&ans,vector<int>&sz,vector<vector<int>>&graph){
        int n=graph.size();
        for(auto &x:graph[src]){
            if(x==par)continue;
            ans[x]=ans[src]+n-2*sz[x];
            dfs(x,src,ans,sz,graph);
        }
        return;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(auto &x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int>sz(n,0);
        vector<int>ans(n);
        precomp(0,-1,sz,graph);
        run(0,-1,0,ans,graph);
        dfs(0,-1,ans,sz,graph);
        return ans;
    }
};