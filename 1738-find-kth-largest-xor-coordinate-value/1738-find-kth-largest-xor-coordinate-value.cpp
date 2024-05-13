class Solution {
public:
    int kthLargestValue(vector<vector<int>>& grid, int k) {
        int r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=1;j<c;j++){
                grid[i][j]^=grid[i][j-1];
            }
        }
        for(int j=0;j<c;j++){
            for(int i=1;i<r;i++){
                grid[i][j]^=grid[i-1][j];
            }
        }
        priority_queue<int>pq;
        for(auto &x:grid){
            for(auto &y:x)pq.push(y);
        }
        for(int i=1;i<k;i++){
            pq.pop();
        }
        return pq.top();
    }
};