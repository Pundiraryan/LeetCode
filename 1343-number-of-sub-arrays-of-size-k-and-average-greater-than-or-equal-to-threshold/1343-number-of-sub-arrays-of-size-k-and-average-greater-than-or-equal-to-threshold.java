class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
         int ms=k*threshold;
        int ans=0,cs=0;
        for(int i=0;i<k;i++)cs+=arr[i];
        if(cs>=ms)ans++;
        for(int i=k;i<arr.length;i++){
            cs+=arr[i];
            cs-=arr[i-k];
            if(cs>=ms)ans++;
        }
        return ans;
    }
}