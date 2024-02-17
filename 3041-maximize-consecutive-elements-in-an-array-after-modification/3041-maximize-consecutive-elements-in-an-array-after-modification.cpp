class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int>dp;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            dp[x+1]=max(dp[x+1],1+dp[x]);
            dp[x]=max(dp[x],1+dp[x-1]);
            ans=max({ans,dp[x],dp[x+1]});
        }
        return ans;
    }
};