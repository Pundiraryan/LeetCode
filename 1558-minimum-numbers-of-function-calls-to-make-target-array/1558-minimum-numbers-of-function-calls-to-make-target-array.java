class Solution {
    public int minOperations(int[] nums) {
        int n=nums.length;
        int ans=0;
        int maxp=0;
        for(int i=0;i<n;i++){
            int fo=0,so=0;
            while(nums[i]>0){
                if(nums[i]%2==1){
                    fo++;
                    nums[i]--;
                }else{
                    so++;
                    nums[i]/=2;
                }
            }
            maxp=Math.max(maxp,so);
            ans+=fo;
        }
        ans+=maxp;
        return ans;
    }
}