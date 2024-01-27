#define mod 1000000007
class Solution {
public:
    int dp[1005][1005];
    int f(int n,int k){
        if(k==0)return 1;
        if(n<=0)return 0;
        if(k<0)return 0;
        if(dp[n][k]!=-1)return dp[n][k];
        int ans=0;
        for(int i=0;i<=min(n-1,k);i++){
            ans=(ans+f(n-1,k-i))%mod;
        }
        return dp[n][k]=ans;
  }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return f(n,k);
    }
};