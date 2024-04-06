#define mod 1000000007
#define ll long long
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
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            ll cnt=(power(2,i,mod)-power(2,n-1-i,mod)+mod)%mod;
          ans=(ans+(ll)cnt*nums[i])%mod;  
        }
        return ans;
    }
};