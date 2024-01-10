class Solution {
public:
    int dp[100005][3];
    int f(int i,int sn,int k,vector<int>&ps){
        int n=ps.size();
        if(sn==2)return 0;
        if(i>=n)return 0;
        if(dp[i][sn]!=-1)return dp[i][sn];
        int nottake=f(i+1,sn,k,ps);
        auto idx=upper_bound(ps.begin(),ps.end(),ps[i]+k);
        int nidx=idx-ps.begin();
        int take=(nidx-i)+f(nidx,sn+1,k,ps);
        return dp[i][sn]=max(take,nottake);
    }
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n=prizePositions.size();
        memset(dp,-1,sizeof(dp));
        return f(0,0,k,prizePositions);
    }
};