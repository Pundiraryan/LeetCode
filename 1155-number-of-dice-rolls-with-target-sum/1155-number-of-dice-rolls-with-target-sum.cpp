#define mod 1000000007
class Solution {
public:
    int dp[35][1005];
      int f(int i,int t,int n,int k){
        if(i==n &&t==0)return 1;
        if(i>=n)return 0;
        if(dp[i][t] != -1)return dp[i][t];
        int ans = 0;
        for(int j= 1; j <= min(k,t); j++){
            ans = (ans+f(i+1,t-j,n,k))%mod;
        }
        return dp[i][t] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return f(0,target,n,k);
    }
};