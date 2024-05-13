class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            if(grid[i][0]==0){
                for(int j=0;j<c;j++)grid[i][j]^=1;
            }
        }
        int ans=r*(1<<(c-1));
        for(int j=1;j<c;j++){
            int cnt0=0,cnt1=0;
            for(int i=0;i<r;i++){
                if(grid[i][j])cnt1++;
                else cnt0++;
            }
            ans+=(max(cnt1,cnt0)*(1<<(c-1-j)));
        }
        return ans;
    }
};