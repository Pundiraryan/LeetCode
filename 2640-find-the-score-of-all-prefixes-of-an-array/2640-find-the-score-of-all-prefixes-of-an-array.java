class Solution {
    public long[] findPrefixScore(int[] nums) {
     int n=nums.length;
        long[] ans=new long[n];
        int val=0;
        for(int i=0;i<n;i++){
            val=Math.max(val,nums[i]);
            ans[i]=nums[i]+val;
        }
        for(int i=1;i<n;i++)ans[i]+=(long)(ans[i-1]);
        return ans;
    }
}