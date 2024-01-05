class Solution {
    public int lengthOfLIS(int[] nums) {
        int ans=0;
        int n=nums.length;
        int[] dp=new int[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=Math.max(dp[i],1+dp[j]);
                }
            }
        }
        for(int i=0;i<n;i++)ans=Math.max(ans,dp[i]);
        return 1+ans;
    }
}