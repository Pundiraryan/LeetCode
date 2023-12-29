class Solution {
public:
    int dp[305][15];
    int f(int i,int dn, int d,vector<int>&jd){
        int n=jd.size();
        if(dn>d)return 1e9;
        if(i==n && dn==d)return 0;
        if(i==n)return 1e9;
        if(dp[i][dn]!=-1)return dp[i][dn];
        int ans=1e9,maxi=jd[i];
        for(int j=i;j<n;j++){
            maxi=max(maxi,jd[j]);
            ans=min(ans,maxi+f(j+1,dn+1,d,jd));
        }
        return dp[i][dn]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n)return -1;
        memset(dp,-1,sizeof(dp));
        return f(0,0,d,jobDifficulty);
    }
};