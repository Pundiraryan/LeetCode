class Solution {
public:
    map<pair<int, int>,int>fre;
    int precomp(vector<vector<int>>& graph, int src, vector<int>& vis){
        vis[src] = 1;
        int ans = 0;
        for(auto i: graph[src]){
            if(!vis[i]){
                ans += (fre.count({src, i}) + precomp(graph, i, vis));
            }
        }
        return ans;
    }
    int res = 0;
    void dfs(vector<vector<int>>& graph, vector<int>& vis, int k, int src, int ans){
        if(ans >= k) res++;
        vis[src] = 1;
        for(auto i: graph[src]){
            if(!vis[i]){
                dfs(graph, vis, k, i, ans - fre.count({src, i}) + fre.count({i, src}));
            }
        }
    }
    
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size()+1;
        vector<vector<int>> graph(n);
        for(auto i: edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        for(auto i: guesses){
            fre[{i[0], i[1]}] = 1;
        }
        vector<int> vis(n,0);
        vector<int>nvstd(n,0);
        int ans = precomp(graph, 0, vis);
        dfs(graph, nvstd, k, 0, ans);
        return res;
    }
};