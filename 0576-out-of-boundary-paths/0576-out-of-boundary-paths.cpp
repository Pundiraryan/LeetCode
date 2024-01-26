vector<pair<int,int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
#define mod 1000000007
class Solution {
public:
    int dp[52][52][52];
    bool isvalid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    int f(int i,int j,int t,int m,int n){
        if(t<0)return 0;
        if(!isvalid(i,j,m,n))return 1;
        if(dp[i][j][t]!=-1)return dp[i][j][t];
        int ans=0;
        for(auto &x:dirs){
            int ni=i+x.first;
            int nj=j+x.second;
            ans=(ans+f(ni,nj,t-1,m,n))%mod;
        }
        return dp[i][j][t]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return f(startRow,startColumn,maxMove,m,n);
    }
};