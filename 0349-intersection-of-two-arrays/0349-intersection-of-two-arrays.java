class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        ArrayList<Integer>al=new ArrayList<>();
        HashMap<Integer,Integer>fre=new HashMap<>();
        for(int val:nums1){
            fre.put(val,fre.getOrDefault(val,0)+1);
        }
        for(int val:nums2){
            if(al.contains(val))continue;
            if(fre.getOrDefault(val,0)>0){
                al.add(val);
            }
        }
         int[] arr = new int[al.size()];
        for (int i = 0; i < al.size(); i++)
            arr[i] = al.get(i);
        return arr;
 
    }
}