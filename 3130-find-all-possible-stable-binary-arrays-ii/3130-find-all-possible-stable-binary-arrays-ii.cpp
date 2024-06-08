#define mod 1000000007
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
       vector<vector<vector<long long>>>dp(zero+1,vector<vector<long long>>(one+1, vector<long long>(3,0)));
        for(int zc=1;zc<=min(zero,limit);zc++)dp[zc][0][0]=1;
        for(int oc=1;oc<=min(one,limit);oc++)dp[0][oc][1]=1;
        for(int zc=1;zc<=zero;zc++){
            for(int oc=1;oc<=one;oc++){
                dp[zc][oc][0]=(dp[zc-1][oc][0]+dp[zc-1][oc][1])%mod;
                dp[zc][oc][1]=(dp[zc][oc-1][1]+dp[zc][oc-1][0])%mod;
                if(zc>limit)dp[zc][oc][0]=(dp[zc][oc][0]-dp[zc-limit-1][oc][1]+mod)%mod;
                if(oc>limit)dp[zc][oc][1]=(dp[zc][oc][1]-dp[zc][oc-limit-1][0]+mod)%mod;
            }
        }
        long long ans=dp[zero][one][1]%mod;
        ans=(ans+dp[zero][one][0])%mod;
        return ans;
        
    }
};