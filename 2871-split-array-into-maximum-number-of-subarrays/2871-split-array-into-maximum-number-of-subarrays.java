class Solution {
    public int maxSubarrays(int[] nums) {
        int n=nums.length;
        int minand=-1;
        for(int i=0;i<n;i++){
            minand&=nums[i];
        }
        if(minand!=0)return 1;
        int currand=-1,ans=0;
        for(int i=0;i<n;i++){
            currand&=nums[i];
            if(currand==0){
                ans++;
                if(i!=n-1)currand=nums[i+1];
            }
        }
        return ans;
    }
}