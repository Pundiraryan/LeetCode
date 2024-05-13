class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int mv=grid[0][0]%x;
        int r=grid.size(),c=grid[0].size();
        vector<int>v;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]%x!=mv)return -1;
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
            int tv=v[(r*c)/2];
            int ans=0;
            for(int i=0;i<r*c;i++)ans+=(abs(v[i]-tv)/x);
            return ans;
        
    }
};