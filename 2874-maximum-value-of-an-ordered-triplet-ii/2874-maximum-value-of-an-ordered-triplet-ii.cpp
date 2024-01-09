#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll n=nums.size();
        vector<ll>premax(n,-1),suffmax(n,-1);
        premax[0]=nums[0];
        suffmax[n-1]=nums[n-1];
        for(ll i=1;i<n;i++)premax[i]=max(premax[i-1],(ll)nums[i]);
        for(ll i=n-2;i>=0;i--)suffmax[i]=max(suffmax[i+1],(ll)nums[i]);
        ll ans=-1;
        for(ll i=1;i<n-1;i++){
            ll val=(ll)(premax[i-1]-nums[i]);
            if(val<0)continue;
            val*=(ll)suffmax[i+1];
            ans=max(ans,val);
        }
        return max(ans,(ll)0);
    }
};