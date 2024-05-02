class Solution {
    public int findMaxK(int[] nums) {
        HashMap<Integer,Integer>fre=new HashMap<>();
        for(int val:nums){
            fre.put(val,fre.getOrDefault(val,0)+1);
        }
        int ans=-1;
        for(int val:nums){
            if(fre.getOrDefault(-val,0)>0){
                ans=Math.max(ans,val);
            }
        }
        return ans;
    }
}