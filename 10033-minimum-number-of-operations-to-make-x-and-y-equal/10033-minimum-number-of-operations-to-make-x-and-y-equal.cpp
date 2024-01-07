class Solution {
public:
    int dp[10005];
    int f(int x, int y)
    {
        if(x <= y)return y-x;
        if(dp[x] != -1)return dp[x];
        int ans = 1e9;
        if(x % 11 == 0) {
            ans = min(ans,1+f(x/11,y));
        }
        else {
            ans = min(ans,x%11 + 1 + f(x/11,y));
            ans = min(ans,(11 - x%11) + 1 + f(x/11+1,y));
        }
        if(x % 5 == 0) {
            ans = min(ans,1+f(x/5,y));
        }
        else {
            ans = min(ans,x%5 + 1 + f(x/5,y));
            ans = min(ans,(5 - x%5) + 1 + f(x/5+1,y));
        }
        ans = min(ans,1 + f(x-1,y));   
        return dp[x] = ans;
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        if(y>=x)return y-x;
        memset(dp,-1,sizeof(dp));
        return f(x,y);
    }
};