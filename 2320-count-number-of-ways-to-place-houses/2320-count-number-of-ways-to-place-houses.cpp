#define  mod 1000000007
class Solution {
public:
    int dp[10005][2];
    int f(int i,int pr,int n){
        if(i==n)return 1;
        if(dp[i][pr]!=-1)return dp[i][pr];
        if(pr){
            return dp[i][pr]=f(i+1,0,n);
        }
        return dp[i][pr]=(f(i+1,1,n)+f(i+1,0,n))%mod;
    }
    int countHousePlacements(int n) {
        memset(dp,-1,sizeof(dp));
        long long val=f(0,0,n);
        val=(val*val)%mod;
        return val;
    }
};