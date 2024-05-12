class Solution {
public:
    vector<pair<int,int>>dirs={{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>ans(n-2,vector<int>(n-2));
        for(int i=1;i<n-1;i++){
            for(int j=1;j<n-1;j++){
                priority_queue<int>pq;
                for(auto &x:dirs){
                    pq.push(grid[i+x.first][j+x.second]);
                }
                ans[i-1][j-1]=pq.top();
            }
        }
        return ans;
    }
};