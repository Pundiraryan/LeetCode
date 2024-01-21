class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>>dist(n+1,vector<int>(n+1,1e9));
        for(int i=2;i<=n-1;i++){
            dist[i][i]=0;
            dist[i][i+1]=1;
            dist[i][i-1]=1;
        }
        dist[1][1]=0;dist[n][n]=0;
        dist[1][2]=1;dist[n][n-1]=1;
        dist[x][y]=1;dist[y][x]=1;
        if(x==y){
            dist[x][y]=0;dist[y][x]=0;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if (dist[i][j] > (dist[i][k] + dist[k][j]))dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        vector<int>ans(n,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(dist[j][k]==i){
                        ans[i-1]++;
                    }
                }
            }
        }
        
        return ans;
    }
};