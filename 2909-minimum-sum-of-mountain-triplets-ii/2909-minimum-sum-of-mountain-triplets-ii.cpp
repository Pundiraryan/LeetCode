class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>premin(n,INT_MAX);
        vector<int>suffmin(n,INT_MAX);
        premin[0]=nums[0];
        suffmin[n-1]=nums[n-1];
        for(int i=1;i<n;i++)premin[i]=min(premin[i-1],nums[i]);
        for(int i=n-2;i>=0;i--)suffmin[i]=min(suffmin[i+1],nums[i] );
        int ans=INT_MAX;
        for(int j=1;j<n-1;j++){
            if(premin[j-1]<nums[j] && suffmin[j+1]<nums[j]){
                ans=min(ans,premin[j-1]+suffmin[j+1]+nums[j]);
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};