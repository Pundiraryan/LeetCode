class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<int>zcr(r),ocr(r);
        vector<int>zcc(c),occ(c);
        for(int i=0;i<r;i++){
            int z=0,o=0;
            for(int j=0;j<c;j++){
                if(grid[i][j])o++;
                else z++;
            }
            zcr[i]=z;ocr[i]=o;
        }
        for(int j=0;j<c;j++){
            int o=0,z=0;
            for(int i=0;i<r;i++){
                if(grid[i][j])o++;
                else z++;
            }
            zcc[j]=z;occ[j]=o;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                grid[i][j]=ocr[i]+occ[j]-zcr[i]-zcc[j];
            }
        }
        return grid;
    }
};