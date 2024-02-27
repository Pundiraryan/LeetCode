#define ll long long
class Solution {
public:
    ll f(ll i,vector<vector<int>>&rides,vector<ll>&dp){
        ll n=rides.size();
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
         vector<int> v={rides[i][1],0,0};
        ll idx=lower_bound(rides.begin(),rides.end(),v)-rides.begin();
        ll case1=rides[i][2]+rides[i][1]-rides[i][0] + f(idx,rides,dp);
        ll case2=f(i+1,rides,dp);
        return dp[i]=max(case1,case2);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<ll>dp(rides.size()+1,-1);
        sort(rides.begin(),rides.end());
        return f(0,rides,dp);
    }
};