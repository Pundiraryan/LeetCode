class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n=nums.length;
        int[] ans=new int[n];
        int ip=0,in=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[ip]=nums[i];
                ip+=2;
            }else{
                ans[in]=nums[i];
                in+=2;
            }
        }
        return ans;
    }
}