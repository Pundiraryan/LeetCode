class Solution {
    public int[][] divideArray(int[] nums, int k) {
        int n=nums.length;
        int[][] ans = new int[n/3][3];
        int[][]eans=ans;
        int i=0;
        Arrays.sort(nums);
        while(i<n){
            int val1=nums[i],val2=nums[i+1],val3=nums[i+2];
            if(val2-val1>k || val3-val2>k || val3-val1>k){
               return new int[0][];
            }
            int[] curr=new int[3];
            curr[0]=val1;curr[1]=val2;curr[2]=val3;
            ans[i/3]=curr;
            i+=3;
        }
        return ans;
    }
}