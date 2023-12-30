#define ll long long
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll sum=0;
        ll n=nums.size();
        vector<ll>ps(n);
        for(ll i=0;i<n;i++){
            sum+=nums[i];
            ps[i]=(sum);
        }
        for(ll i=n-1;i>=2;i--){
            if(ps[i-1]>nums[i])return ps[i-1]+nums[i];
        }
        return -1;
    }
};