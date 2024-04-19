class Solution {
public:
    vector<pair<int,int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
    bool check(int i,int j,int r,int c){
        if(i<0 || i>=r||j<0||j>=c)return false;
        return true;
    }
    void dfs(vector<vector<char>>& grid,int i,int j){
        int r=grid.size();
        int c=grid[0].size();
        grid[i][j]='*';
        for(auto d:dirs){
            int nx=i+d.first;
            int ny=j+d.second;
            if(check(nx,ny,r,c)){
                if(grid[nx][ny]=='1'){
                    dfs(grid,nx,ny);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};