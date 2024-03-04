class Solution {
    public int minPatches(int[] nums, int n) {
        int ans=0;
        long curr=0;
        int i=0;
        while(curr<n){
             if(i<nums.length && nums[i]<=curr+1){
                     curr+=nums[i++];
                }else{
                    ans++;
                  curr*=2;
                  curr++;
                }
        }
        return ans;
    }
}