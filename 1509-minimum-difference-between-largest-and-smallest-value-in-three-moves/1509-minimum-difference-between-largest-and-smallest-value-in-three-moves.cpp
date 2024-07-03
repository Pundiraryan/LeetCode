class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1)return 0;
        int ans=nums[n-1]-nums[0];
        ans=min({ans,nums[n-1]-nums[1],nums[n-2]-nums[0]});
        if(n==2)return ans;
        ans=min({ans,nums[n-1]-nums[2],nums[n-3]-nums[0],nums[n-2]-nums[1]});
        if(n==3)return ans;
        ans=min({ans,nums[n-1]-nums[3],nums[n-2]-nums[2],nums[n-3]-nums[1],nums[n-4]-nums[0]});
        return ans;
    }
};