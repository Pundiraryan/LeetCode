class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        int  r=land.size(),c=land[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(land[i][j]==0)continue;
                int ci=i,cj=j;
                while(cj<c && land[i][cj]==1)cj++;
                while(ci<r && land[ci][j]==1)ci++;
                if(cj)cj--;
                if(ci)ci--;
                ans.push_back({i,j,ci,cj});
                for(int a=i;a<=ci;a++){
                    for(int b=j;b<=cj;b++){
                        land[a][b]=0;
                    }
                }
            }
        }
        return ans;
    }
};