#define mod 1000000007
class Solution {
public:
    long long f(int pos,int k,vector<vector<long long>>&dp){
        if(pos<1){
            if(k==0)return 1;
            else return 0;
        }
        if(k==0)return 0;
        if(dp[pos][k]!=-1)return dp[pos][k];
        long long ans=0;
        long long notvis=(pos-1)*f(pos-1,k,dp);
        long long vis=f(pos-1,k-1,dp);
        ans=(ans+vis)%mod;
        ans=(ans+notvis)%mod;
        return dp[pos][k]= ans;
    }
    int rearrangeSticks(int n, int k) {
        vector<vector<long long>>dp(n+1,vector<long long>(k+1,-1));
        return f(n,k,dp);
    }
};