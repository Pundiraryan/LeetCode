class Solution {
public:
    int f(int i,int fn,vector<int>&prices,vector<vector<int>>&dp){
        int n=prices.size();
        if(fn>=n)return 0;
        if(i>=n+1)return 0;
        if(dp[i][fn]!=-1)return dp[i][fn];
        int take=prices[i-1]+f(i+1,i*2,prices,dp);
        int nottake=1e9;
        if(i<=fn)nottake=f(i+1,fn,prices,dp);
        return dp[i][fn]=min(take,nottake);
        
    }
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,0,prices,dp);
    }
};