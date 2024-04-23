class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        vector<vector<int>>graph(n);
        vector<int>deg(n,0);
        for(auto &x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
            deg[x[0]]++;
            deg[x[1]]++;
        }
        int lft=n;
        queue<int>bfs;
        for(int i=0;i<n;i++){
            if(deg[i]==1)bfs.push(i);
        }
        while(lft>2){
            int sz=bfs.size();
            lft-=sz;
            while(sz--){
                int val=bfs.front();
                bfs.pop();
                for(auto &x:graph[val]){
                    deg[x]--;
                    if(deg[x]==1){
                        bfs.push(x);
                    }
                }
                
            }
        }
        vector<int>ans;
        while(!bfs.empty()){
            ans.push_back(bfs.front());
            bfs.pop();
        }
        return ans;
    }
};