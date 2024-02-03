class Solution {
    int f(int i,int k,int n,int[] arr,int []dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=-1,maxi=-1;
        for(int j=i;j<Math.min(i+k,n);j++){
            maxi=Math.max(maxi,arr[j]);
            ans=Math.max(ans,(j-i+1)*maxi+f(j+1,k,n,arr,dp));
        }
        return dp[i]=ans;
        
    }
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n=arr.length;
        int []dp=new int[n+1];
        for(int i=0;i<n+1;i++)dp[i]=-1;
        return f(0,k,n,arr,dp);
    }
}