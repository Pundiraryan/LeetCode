class Solution {
public:
    int dp[105][105];
    int cnt(int c,int n,int rl){
        int sb=abs(c-n);
        int sa=rl-sb;
        return min(sa,sb);
    }
    int f(int i,int j,string&r,string &k){
        int n=r.length(),m=k.length();
        if(j==m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1e9;
        for(int a=0;a<n;a++){
            if(r[a]==k[j]){
                ans=min(ans,1+cnt(i,a,n)+f(a,j+1,r,k));
            }
        }
        return dp[i][j]=ans;
    }
    int findRotateSteps(string ring, string key) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,ring,key);
    }
};