class Solution {
  
    int mod=1000000007;
    int f(int i,int lc,int ec,int tc,int n,int[][][][] dp){
        if(i==n){
            if(lc==1 && ec==2 && tc==1)return 1;
            return 0;
        }
        if(dp[i][lc][ec][tc]!=-1)return dp[i][lc][ec][tc];
        int ans=0;
        for(char ch='a';ch<='z';ch++){
            if(ch=='l'){
                ans=(ans+f(i+1,Math.min(lc+1,1),ec,tc,n,dp))%mod;
            }
            else if(ch=='e'){
                ans=(ans+f(i+1,lc,Math.min(2,ec+1),tc,n,dp))%mod;
            }
            else if(ch=='t'){
                ans=(ans+f(i+1,lc,ec,Math.min(tc+1,1),n,dp))%mod;
            }
            else{
                ans=(ans+f(i+1,lc,ec,tc,n,dp))%mod;
            }
        }
        return dp[i][lc][ec][tc]=ans;
    }
    public int stringCount(int n) {
          int[][][][] dp=new int[n+2][2][3][2];
        for(int i=0;i<n+2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<3;k++){
                    for(int l=0;l<2;l++){
                        dp[i][j][k][l]=-1;
                    }
                }
            }
        }
        return f(0,0,0,0,n,dp);
    }
}