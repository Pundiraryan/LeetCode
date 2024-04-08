#define ll long long
class Solution {
public:
    ll dp[105][105][105];
    ll f(int prev,int i,int k,vector<vector<int>>&dis)
    {
        int n=dis.size()-1;
        if(i > n){
            if(k==0)return 0;
            return 1e12;
        }
        if(k == 0)
        {
            ll sum = 0; 
            for(int j = prev + 1; j <= n; j++)
            {
                sum += dis[prev][j];
            }
            return sum;
        }
        
        if(dp[prev][i][k] != -1) return dp[prev][i][k];
        ll a = f(prev,i+1,k,dis); 
        ll sum = 0;
        for(int j = prev + 1; j < i; j++)
        {
            if(prev != 0) sum += min(dis[prev][j], dis[i][j]);
            else sum += dis[i][j];
        }
        ll b = sum +f(i,i+1,k-1,dis);
        return dp[prev][i][k] = min(a, b);
    }
    
    int minDistance(vector<int>& house, int k) {
        memset(dp,-1,sizeof(dp));
        int n = house.size();
        vector<vector<int>>dis(n+1,vector<int>(n+1));
        sort(house.begin(), house.end());
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dis[i + 1][j + 1] = abs(house[i] - house[j]);
            }
        }
        return f(0,1,k,dis);
    }
};