class Solution {
public:
    int dp[1005][1005][2];
    int f(int i,int j,int ts,int t,vector<int>&stones){
        if(i>=j)return 0;
        if(dp[i][j][t]!=-1)return dp[i][j][t];
        if(!t){
            int case1=ts-stones[i]+f(i+1,j,ts-stones[i],t^1,stones);
            int case2=ts-stones[j] + f(i,j-1,ts-stones[j],t^1,stones);
            return dp[i][j][t]=max(case1,case2);
        }
            int case1=-(ts-stones[i])+f(i+1,j,ts-stones[i],t^1,stones);
            int case2=-(ts-stones[j]) + f(i,j-1,ts-stones[j],t^1,stones);
            return dp[i][j][t]=min(case1,case2);
        
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        memset(dp,-1,sizeof(dp));
        int ts=0;
        for(auto &x:stones)ts+=x;
        return f(0,n-1,ts,0,stones);
    }
};
