#define mod 1000000007
#define ll long long

class Solution {
public:
  ll power(ll x, ll y, ll p)
{
ll res = 1; // Initialize result
x = x % p; // Update x if it is more than or equal to p
while (y > 0)
{
// If y is odd, multiply x with result
if (y & 1)
res = (res * x) % p;
// y must be even now
y = y >> 1; // y = y/2
x = (x * x) % p;
}
return res;
}
    ll pow[105];
    long long dp[105][105][105];
    long long f(int i,int len,int csum,int k,vector<int>&nums){
        int n=nums.size();
        if(csum==k){
            return pow[n-len];
        }
        if(csum>k || i==n)return 0;
        if(dp[i][len][csum]!=-1)return dp[i][len][csum];
        ll ans=0;
        ans=(ans+f(i+1,len,csum,k,nums))%mod;
        ans=(ans+f(i+1,len+1,csum+nums[i],k,nums))%mod;
        return dp[i][len][csum]=ans;
    }
    int sumOfPower(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        pow[0]=1;
        for(ll i=1;i<102;i++)pow[i]=(pow[i-1]*2)%mod;
        return f(0,0,0,k,nums);
    }
};