#define mod 1000000007
#define ll long long
class Solution {
public:
    ll dp[100002][3][4];
    ll f(int i,int abs,int late,int n){
        if(abs >= 2) return 0;
        if(late >= 3) return 0;
        if(i==n)return 1;
        if(dp[i][abs][late] != -1) return dp[i][abs][late];
        int ans = 0;
        ans = (ans + f(i+1,abs,0,n)%mod)%mod;
        ans = (ans + f(i+1,abs+1,0,n)%mod)%mod;
        ans = (ans + f(i+1,abs,late+1,n)%mod)%mod;

        return dp[i][abs][late] = ans%mod;
    }
    int checkRecord(int n) {
         memset(dp,-1,sizeof(dp));
        return f(0,0,0,n);
    }
};