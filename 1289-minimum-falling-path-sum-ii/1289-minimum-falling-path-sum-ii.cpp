class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1)return grid[0][0];
        vector<vector<int>>dp(n+1,vector<int>(n+1,1e9));
        for(int i=0;i<=n;i++)dp[n][i]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                for(int k=n-1;k>=0;k--){
                    if(k==j)continue;
                    dp[i][j]=min(dp[i][j],dp[i+1][k]+grid[i][k]);
                }       
            }
        }
        int ans=1e9;
        for(auto &x:dp[0])ans=min(ans,x);
        return ans;
    }
};