class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer>al=new ArrayList<Integer>();
        for(int val:nums){
            int idx=Math.abs(val);
            if(nums[idx-1]<0)al.add(idx);
            nums[idx-1]*=-1;
        }
        return al;
    }
}