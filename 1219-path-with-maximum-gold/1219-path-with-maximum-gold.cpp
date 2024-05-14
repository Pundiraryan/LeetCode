vector<pair<int,int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
public:
    int dfs(int i,int j,int r,int c,vector<vector<int>>&grid){
        if(i<0 || i>=r ||j<0 ||j>=c )return 0;
        if(!grid[i][j])return 0;
        int ov=grid[i][j];
        grid[i][j]=0;
        int ans=0;
        for(auto &d:dirs){
            int ni=i+d.first,nj=j+d.second;
            ans=max(ans,dfs(ni,nj,r,c,grid));
        }
        grid[i][j]=ov;
        return ans+ov;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        int r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]){
                    ans=max(ans,dfs(i,j,r,c,grid));
                }
            }
        }
        return ans;
    }
};