class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int>premax(n),suffmin(n);
        premax[0]=nums[0],suffmin[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            premax[i]=max(premax[i-1],nums[i]);
            suffmin[n-1-i]=min(suffmin[n-i],nums[n-1-i]);
        }
        int ans=0;
        for(int i=1;i<=n-2;i++){
            if(premax[i-1]<nums[i] && suffmin[i+1]>nums[i])ans+=2;
            else if(nums[i - 1] < nums[i] && nums[i] < nums[i + 1])ans++;
        }
            return ans;
    }
};