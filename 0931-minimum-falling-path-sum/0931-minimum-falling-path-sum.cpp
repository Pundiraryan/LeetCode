class Solution {
public:
    int dp[102][102];
    int f(int i,int j,int r,int c,vector<vector<int>>&m){
        if(i<0||i>=r||j<0||j>=c)return 1e9;
        if(i==r-1)return m[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=m[i][j]+min({f(i+1,j,r,c,m),f(i+1,j-1,r,c,m),f(i+1,j+1,r,c,m)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=1e9;
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        dp[0]=matrix[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int a=1e9,b=1e9,c=1e9;
                a=dp[i-1][j];
                if(j>0)b=dp[i-1][j-1];
                if(j<n-1)c=dp[i-1][j+1];
                dp[i][j]=matrix[i][j]+min(a,min(b,c));
            }
        }
        for(int i=0;i<n;i++)ans=min(ans,dp[n-1][i]);
        return ans;
    }
};