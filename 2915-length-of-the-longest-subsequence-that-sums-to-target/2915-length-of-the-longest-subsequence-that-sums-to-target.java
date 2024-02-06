class Solution {
    int f(int i,int t,List<Integer>nums,int[][] dp){
        if(t<0)return -10000000;
        if(t==0)return 0;
        if(i>=nums.size() && t!=0)return -10000000;
          if(dp[i][t]!=-1)return dp[i][t];
        int nottake=f(i+1,t,nums,dp);
        int take=1+f(i+1,t-nums.get(i),nums,dp);
        return dp[i][t]=Math.max(take,nottake);
    }
    public int lengthOfLongestSubsequence(List<Integer> nums, int target) {
        int n=nums.size();
        int[][] dp=new int[n+1][target+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=target;j++){
                dp[i][j]=-1;
            }
        }
        int ans=f(0,target,nums,dp);
        return Math.max(ans,-1);
    }
}