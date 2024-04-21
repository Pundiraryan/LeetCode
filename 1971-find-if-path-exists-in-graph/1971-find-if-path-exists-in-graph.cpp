class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<int>& vstd, int src, int des) {
        if(src==des)return true;
        if(vstd[src])return false;
        vstd[src] = 1;
        for(auto &x:graph[src]){
            if(dfs(graph,vstd,x,des))return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> graph(n);
        for(auto &x:edges) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> visited(n, 0);
        return dfs(graph, visited, start, end);
    }
};