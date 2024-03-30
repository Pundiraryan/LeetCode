class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            ans+=(upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]));
        }
            return ans;
    }
};