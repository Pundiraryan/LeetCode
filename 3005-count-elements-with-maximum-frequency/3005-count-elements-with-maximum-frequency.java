class Solution {
    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer,Integer>fre=new HashMap<>();
        int maxfreq=1;
        for(int val:nums){
            int x=fre.getOrDefault(val,0)+1;
            fre.put(val,x);
            maxfreq=Math.max(maxfreq,x);
        }
        int ans=0;
        for(Map.Entry<Integer,Integer>p:fre.entrySet()){
            if(p.getValue()==maxfreq){
                ans++;
            }
        }
        return ans*maxfreq;
        
    }
}