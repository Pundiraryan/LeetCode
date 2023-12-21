class Solution {
public:
    long long dp[100005];
    long long f(int i,int k,vector<int>&nums){
        long long n=nums.size();
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        long long ans=LONG_MAX;
        long long addval=max(0,k-nums[i]);
        ans=min(ans,addval+f(i+1,k,nums));
         ans=min(ans,addval+f(i+2,k,nums));
         ans=min(ans,addval+f(i+3,k,nums));
        return dp[i]=ans;
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        long long n=nums.size();
        memset(dp,-1,sizeof(dp));
        long long ans=f(0,k,nums);
        ans=min(ans,f(1,k,nums));
        ans=min(ans,f(2,k,nums));
        return ans;
    }
};