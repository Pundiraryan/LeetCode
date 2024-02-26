#define mod 1000000007
class Solution {
public:
    int dp[1005];
    int f(int dn,int n,int d,int fd){
        if(dn>n)return 0;
        int ans=0;
        if(dp[dn]!=-1)return dp[dn];
        for(int j=dn+d;j<dn+fd;j++){
            ans=(ans + f(j,n,d,fd))%mod;
        }
        if(dn+fd>n)ans++;
        return dp[dn]=ans;
        
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp,-1,sizeof(dp));
        return f(1,n,delay,forget);  
    }
};