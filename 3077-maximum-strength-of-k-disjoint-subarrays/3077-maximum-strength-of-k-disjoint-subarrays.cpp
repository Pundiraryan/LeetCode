
#define ll long long
class Solution {
public:
    ll f(int i,ll k, int s, vector<int>& nums,vector<vector<vector<ll>>>& dp) {
        int n=nums.size();
        if (k<0) return -1e18;
        if (i==n) {
            if (k==0) return 0;
            return -1e18;
        }
        if (dp[i][k][s] != -1) return dp[i][k][s];
        ll ans = -1e18;
        ll val1=f(i+1,k,0,nums,dp);
        ll val2=f(i+1,k-1,1,nums,dp);
        ll  x = (k & 1); 
        if (s) {
            ans =max(ans, f(i+1,k,s,nums,dp)); 
        }
        if (x == 1) {
            ans =max(ans, nums[i]*k+max(val1,val2)); 
        } else {
            ans=max(ans,max(val1,val2) - nums[i]*k);
        }
        return dp[i][k][s] = ans;
    }

    ll maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(3, -1)));
        return f(0,k,1,nums,dp);
    }
};