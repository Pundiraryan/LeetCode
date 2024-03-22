class Solution {
private:
    int dp[100005][2];
    int f(int i,int t,vector<int>&ps){
        int n=ps.size();
        if(i==n-1){
            if(t)return -ps[i];
            return ps[i];
        }
        if(dp[i][t]!=-1)return dp[i][t];
        if(t==0){
            int case1=ps[i]+f(i+1,t^1,ps);
            int case2=f(i+1,t,ps);
            return dp[i][t]=max(case1,case2);
        }
        int case1=-ps[i]+f(i+1,t^1,ps);
        int case2=f(i+1,t,ps);
        return dp[i][t]=min(case1,case2);
    }
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>ps(n,0);
        ps[0]=stones[0];
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+stones[i];
        }
        return f(1,0,ps);
    }
};