class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        int n=arr.length;
        HashMap<Integer,Integer>fre=new HashMap<Integer,Integer>();
        for(int i=0;i<n;i++){
            fre.put(arr[i],fre.getOrDefault(arr[i],0)+1);
        }
        int total=0;
        List<Integer>lst=new ArrayList<>();
        for(Map.Entry<Integer,Integer> p:fre.entrySet()){
            lst.add(p.getValue());
        }
        Collections.sort(lst);
        int ans=lst.size();
        for(Integer e:lst){
            total+=e;
            if(total>k)break;
            ans--;
        }
        return ans;
    }
}