#define mod 1000000007
class Solution {
public:
    int dp[100005][5];
    long long f(int i,int prev,vector<int>&nums){
        if(i==nums.size())return prev==2;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        long long ans=0;
        if(nums[i]==0){
             ans=(ans+f(i+1,prev,nums))%mod;
            if(prev==-1 || prev==0)ans=(ans+f(i+1,0,nums))%mod;
        }
        else if(nums[i]==1){
            ans=(ans+f(i+1,prev,nums))%mod;
            if(prev==0 || prev==1)ans=(ans+f(i+1,1,nums))%mod;
        }else{
            ans=(ans+f(i+1,prev,nums))%mod;
            if(prev==1||prev==2)ans=(ans+f(i+1,2,nums))%mod;
        }
        return dp[i][prev+1]= ans;
    }
    int countSpecialSubsequences(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,-1,nums);
    }
};