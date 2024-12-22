class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=1;
        sort(nums.begin(),nums.end());
        int fa=nums[0]-k+1;
        for(int i=1;i<n;i++){
            if(fa>nums[i]+k)continue;
            fa=max(fa,nums[i]-k);
            ans++;
            fa++;
        }
        return ans;
    }
};