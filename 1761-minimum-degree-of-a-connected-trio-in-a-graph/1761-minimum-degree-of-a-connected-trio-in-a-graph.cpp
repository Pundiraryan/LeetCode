class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n+1,vector<int>(n+1,0));
        vector<int>deg(n+1,0);
        for(auto &x:edges){
            graph[x[0]][x[1]]=1;
            graph[x[1]][x[0]]=1;
            deg[x[0]]++;
            deg[x[1]]++;
        }
        int ans=1e9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(graph[i][j]==1 && graph[j][k]==1 && graph[k][i]==1){
                    ans=min(ans,deg[i]+deg[j]+deg[k]-6);    
                    }
                }
            }
        }
        if(ans==1e9)return -1;
        return ans;
    }
};