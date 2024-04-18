class Solution {
public:
    vector<pair<int,int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0)continue;
                int cnt=0;
                for(auto &x:dirs){
                    int ci=i+x.first,cj=j+x.second;
                    if(ci<0 || ci>=r ||cj<0||cj>=c)continue;
                    if(grid[ci][cj]==1)cnt++;
                }
                ans+=(4-cnt);
            }
        }
        return ans;
    }
};