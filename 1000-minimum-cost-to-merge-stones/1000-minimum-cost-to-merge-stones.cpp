class Solution {
public:
    int dp[51][51];
    int f(int i,int j,int k,vector<int>&stones,vector<int>&ps){
        if(i>=j)return 0;
        int ans=1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int idx=i;idx<j;idx=idx+k -1){
            ans=min(ans,f(i,idx,k,stones,ps)+f(idx+1,j,k,stones,ps));
        }
        if((j-i)%(k-1)==0)ans=ans+(ps[j+1]-ps[i]);
        return dp[i][j]= ans;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        if((n-1)%(k-1)!=0)return -1;
        memset(dp,-1,sizeof(dp));
        vector<int>ps(n+1,0);
        for(int i=1;i<=n;i++)ps[i]=ps[i-1]+stones[i-1];
        return f(0,n-1,k,stones,ps);
    }
};