class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    
     int bfs(int s, vector<vector<int>>& adj, int& n) {
        vector<int> vis(n , -1);
        vis[s] = 0;
        int depth = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int sz = size(q);
            while(sz--) {
                auto tp = q.front();
                q.pop();
                for(auto& j: adj[tp]) {
                    if (vis[j] == -1) {
                        vis[j] = depth + 1;
                        q.push(j);
                    } else if (abs(vis[j] - depth) != 1) return -1;
                }
            }
            depth++;
        }
        return depth;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        DisjointSet d(n);
        for(auto& e: edges) {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
            d.unionBySize(e[0]-1,e[1]-1);
        }
        unordered_map<int, vector<int>> connectedComponents;
        for(int i = 0; i < n; i++) {
            connectedComponents[d.findUPar(i)].push_back(i);
        }
        int totalNumberofGroup = 0;
        for(auto& [val, nodes] : connectedComponents) {
           int componentGroups = -1; 
            for(auto node: nodes) {
                componentGroups = max(componentGroups, bfs(node,adj,n));
				if (componentGroups == -1) return -1;
            }
            totalNumberofGroup += componentGroups;
        }
        return totalNumberofGroup;

    }

};