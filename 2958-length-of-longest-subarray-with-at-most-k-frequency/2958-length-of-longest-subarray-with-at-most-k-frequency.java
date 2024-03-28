class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int n=nums.length;
        int i=0,j=0,ans=0;
        HashMap<Integer,Integer>fre=new HashMap<>();
        while(j<n){
            fre.put(nums[j],fre.getOrDefault(nums[j],0)+1);
            while(i<=j && fre.getOrDefault(nums[j],0)>k){
                fre.put(nums[i],fre.getOrDefault(nums[i],0)-1);
                i++;
            }
            ans=Math.max(ans,j-i+1);
            j++;
        }
        return ans;
    }
}