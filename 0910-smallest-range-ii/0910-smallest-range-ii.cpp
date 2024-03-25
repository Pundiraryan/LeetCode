class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int ans=1e9;
        int  n=nums.size();
        sort(nums.begin(),nums.end());
        if(n==1)return 0;
        int val1=nums[n-1]-k,val2=nums[0]+k;
        ans=min(ans,nums[n-1]-nums[0]);
        for(int i=0;i<n-1;i++){
            int mnv=min(val2,nums[i+1]-k);
            int mxv=max(val1,nums[i]+k);
            ans=min(ans,mxv-mnv);
        }
        return ans;
    }
};