class Solution {
    int f(int c1,int c2,int r,int[][] grid,int[][][] dp){
         int n=grid.length,m=grid[0].length;
        if(r>=n || c1<0 ||c1>=m ||c2<0 || c2>=m)return 0;
        if(dp[c1][c2][r]!=-1)return  dp[c1][c2][r];
        int ans=grid[r][c1]+grid[r][c2];
        if(c1==c2)ans/=2;
        int res=-1;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                res=Math.max(res,ans+f(c1+i,c2+j,r+1,grid,dp));
            }
        }
        return dp[c1][c2][r]=res;
    }
    public int cherryPickup(int[][] grid) {
          int n=grid.length,m=grid[0].length;
        int[][][] dp=new int[m+1][m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    dp[i][j][k]=-1;
                }
                
            }
        }
        return f(0,m-1,0,grid,dp);
    }
}