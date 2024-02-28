
class Solution {
    public int numberOfUniqueGoodSubsequences(String binary) {
        int n=binary.length();
        int mod=1000000007;
        int[][] dp=new int[2][2];
         // i se start aur j pe khatam
        dp[0][1]=0; dp[1][1]=0;dp[1][0]=0;dp[0][0]=0;
        for(int i=0;i<n;i++){
            if(binary.charAt(i)=='0'){
                dp[0][0]=1; //0 count hoga
                dp[1][0]=(dp[1][0] + dp[1][1])%mod;
            }else{
                dp[1][1]=(dp[1][1]+dp[1][0]+1)%mod;
                // 1 for 1 string
            }
        }
        return (dp[0][0]+dp[1][0]+dp[1][1])%mod;
    }
}