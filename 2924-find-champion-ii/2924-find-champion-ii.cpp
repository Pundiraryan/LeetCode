class Solution {
public:
    
    int findChampion(int n, vector<vector<int>>& edges) {
       int v=n;
        vector<vector<int>>graph(v);
        for(auto &x:edges){
            graph[x[0]].push_back(x[1]);
        }
        vector<int>deg(v,0);
        vector<int>res;
        for(int i=0;i<v;i++){
            for(auto &x:graph[i])
                deg[x]++;
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(!deg[i])q.push(i);
        }
        if(q.size()==0 || q.size()>1)return -1; 
        int counter=0;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            res.push_back(val);
            for(auto &v:graph[val]){
                deg[v]--;
                if(deg[v]==0){
                    q.push(v);
                }
            }
        }
        if(res.size()==v) return res.front();
        return -1;
        
    }
};