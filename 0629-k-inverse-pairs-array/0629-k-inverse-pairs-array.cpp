#define mod 1000000007
class Solution {
public:
    int dp[1005][1005];
    int f(int n,int k){
        if(k==0)return 1;
        if(n<=0)return 0;
        if(k<0)return 0;
        if(dp[n][k]!=-1)return dp[n][k];
        int ans=f(n-1,k);
        ans=(ans+f(n,k-1))%mod;//sliding window
        if(k>=n)ans=(ans-f(n-1,k-n)+mod)%mod;
        return dp[n][k]=ans;
  }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return f(n,k);
    }
};