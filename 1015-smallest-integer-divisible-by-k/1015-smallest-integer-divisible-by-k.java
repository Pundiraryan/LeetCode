class Solution {
    public int smallestRepunitDivByK(int k) {
         if(k%2==0 || k%5==0)return -1;
        long val=1;
        int ans=1;
        while(val%k!=0){
            val*=10;
            val++;
            val%=k;
            ans++;
        }
       return ans;
    }
}