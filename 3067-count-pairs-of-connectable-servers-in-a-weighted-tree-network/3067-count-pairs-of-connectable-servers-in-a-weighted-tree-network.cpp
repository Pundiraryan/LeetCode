class Solution {
public:
    int dfs(int node,int par,int spd,int dist, vector<vector<pair<int,int>>>&graph){
        int res=0;
        if(dist%spd==0)res++;
        for(auto &x:graph[node]){
            int nn=x.first,dv=x.second;
            if(nn==par)continue;
            res+=dfs(nn,node,spd,dist+dv,graph);
        }
        return res;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n=edges.size()+1;
        vector<vector<pair<int,int>>>graph(n);
        for(auto &x:edges){
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int nc=0,res=0;
            for(auto &x:graph[i]){
                int node=x.first,dist=x.second;
                int sc=dfs(node,i,signalSpeed,dist,graph);
                res+=sc*nc;nc+=sc;
            }
            ans[i]=res;
        }
        return ans;
    }
};