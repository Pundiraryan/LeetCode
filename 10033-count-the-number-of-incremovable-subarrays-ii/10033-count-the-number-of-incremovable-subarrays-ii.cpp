#define ll long long 
class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        vector<long long>suff;
        ll n=nums.size();
        ll res=0;
        suff.push_back(nums.back());
        for(ll i=n-2;i>=0;i--){
            if(nums[i]>=nums[i+1])break;
            suff.push_back(nums[i]);
        }
        reverse(suff.begin(),suff.end());
        if(suff.size()==n)return n*(n+1)/2;
        ll prev=-1;
        n-=suff.size();
        for(ll i=0;i<n;i++){
            if(nums[i]>prev){
                prev=nums[i];
                res+=(suff.end()-upper_bound(suff.begin(),suff.end(),prev))+1;
            }else{
                break;
            }
        }
        res+=(suff.size()+1);
        return res;
    }
};