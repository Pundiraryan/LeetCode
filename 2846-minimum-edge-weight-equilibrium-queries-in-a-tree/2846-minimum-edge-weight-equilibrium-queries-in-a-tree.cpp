class Solution {
public:
    int mxlog = 25;
    vector<vector<pair<int,int>>> graph;
    vector<vector<int>> parent;
    vector<int> depth;
    unordered_set<int> W;
    vector<vector<int>> Q;
    int N;
    void dfs(int u,int p = -1,int d = 0,int q = 0){
        depth[u] = d;
        parent[0][u] = p;
        for(auto v:graph[u]){
            if(v.first== p)continue;
            for(auto q:W){
                if(q == v.second)
                    Q[q][v.first] = Q[q][u]+1;
                else 
                    Q[q][v.first] = Q[q][u];
            }
            dfs(v.first,u,d+1,q+v.second);
        }
    }
    void build(){
        for(int i = 0;i<N;i++)for(int j = 0;j<mxlog;j++)parent[j][i] = -1;
        for(int i = 0;i<N;i++)depth[i]= -1;
        dfs(0);
        for(int i = 0;i<N;i++)
            if(depth[i]== -1)dfs(i);

        for(int i = 1;i<mxlog;i++){
            for(int u = 0;u<N;u++){
                if(parent[i-1   ][u]!= -1)
                parent[i][u] = parent[i-1][parent[i-1][u]];
            }
        }
    }
    int lca(int u ,int v){
        if(depth[u]>depth[v])swap(u,v);
        int W = depth[v]-depth[u];
        for(int i = mxlog-1;i>=0;i--){
            if(W & (1<<i))
                v = parent[i][v];
        }
        if(u == v)return u; 

        for(int i = mxlog-1;i>=0;i--){
            if(parent[i][u]!= parent[i][v]){
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }
    int numberOnes(int u,int v,int w,int LCA){
        return Q[w][u]+Q[w][v]-(2*Q[w][LCA]);
    }
    
    
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        N = n;
        graph.resize(n);
        depth.resize(n);
        parent.resize(mxlog,vector<int> (n,-1));
        Q.resize(27,vector<int> (n,0));
        for(int i = 0;i<26;i++){
            Q[i].resize(n);
        }
        
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            W.insert(w);
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        
        }
        build();
        vector<int> ans(queries.size());
        for(int i = 0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];
            int LCA = lca(u,v);
            int len = depth[u]+depth[v]-(2*depth[LCA]);
            int res = len;
                
            for(auto q:W){
                res =  min(res,len- numberOnes(u,v,q,LCA));            
            }
            ans[i] = res;
        }
        return ans;
    }
};