class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& r) {
        unordered_set<int>na;
        for(auto &x:r)na.insert(x);
        vector<vector<int>>graph(n);
        for(auto &x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        queue<int>bfs;
        vector<int>vstd(n,0);
        bfs.push(0);
        vstd[0]=1;
        int ans=1;
        while(!bfs.empty()){
            auto curr=bfs.front();
            bfs.pop();
            for(auto &x:graph[curr]){
                if(vstd[x] || na.find(x)!=na.end())continue;
                vstd[x]=1;
                bfs.push(x);
                ans++;
            }
        }
        return ans;
    }
};