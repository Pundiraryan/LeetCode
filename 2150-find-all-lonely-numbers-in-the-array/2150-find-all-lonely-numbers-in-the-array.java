class Solution {
    public List<Integer> findLonely(int[] nums) {
        List<Integer>ans=new ArrayList<>();
        HashMap<Integer,Integer>fre=new HashMap<>();
        for(int val:nums)fre.put(val,fre.getOrDefault(val,0)+1);
        for(int val:nums){
            if(fre.getOrDefault(val,0)==1 && !fre.containsKey(val+1) && !fre.containsKey(val-1))ans.add(val);
        }
        return ans;
    }
}