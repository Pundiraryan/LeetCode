class Solution {
    public int getMaximumConsecutive(int[] coins) {
        int ans=0;
        int n=coins.length;
        if(n==1 && coins[0]==1)return 2;
        if(n==1)return 1;
        Arrays.sort(coins);
        for(int i=0;i<n;i++){
            if(coins[i]<=ans || coins[i]-ans ==1){
                ans+=coins[i];
            }else{
                break;
            }
        }
        return ans+1;
    }
}