class Solution {
    public long largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length;
        long[] ps=new long[n];
        long cs=0;
        for(int i=0;i<n;i++){
            cs+=nums[i];
            ps[i]=cs;
        }
        for(int i=n-1;i>=2;i--){
            if(nums[i]<ps[i-1])return nums[i]+ps[i-1];
        }
        return -1;
    }
}