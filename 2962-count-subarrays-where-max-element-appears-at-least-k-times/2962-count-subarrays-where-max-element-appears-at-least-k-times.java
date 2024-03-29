class Solution {
    public long countSubarrays(int[] nums, int k) {
        long ans=0;
        int me=0,n=nums.length;
        for(int val:nums)me=Math.max(me,val);
        int i=0,j=0;
        HashMap<Integer,Integer>fre=new HashMap<>();
        while(j<n){
            fre.put(nums[j],fre.getOrDefault(nums[j],0)+1);
            while(fre.getOrDefault(me,0)>=k){
                ans+=(n-j);
                fre.put(nums[i],fre.getOrDefault(nums[i],0)-1);
                i++;
                
            }
            j++;
        }
        return ans;
    }
}