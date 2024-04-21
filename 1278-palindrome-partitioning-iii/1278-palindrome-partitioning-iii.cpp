class Solution {
public:
    int dp[105][105];
    int precomp(string &s){
     int res=0,n=s.length();
        for(int i=0;i<n/2;i++){
            res+=(s[i]!=s[n-1-i]);
        }
        return res;
    }
    int f(int i,int k,string&s,vector<vector<int>>&cost){
        int n=s.length();
        if(i==n){
            if(k==0)return 0;
            else return 1e9;
        }
        if(k==0){
            return cost[i][n-1];
        }
        if(dp[i][k]!=-1)return dp[i][k];
        int ans=1e9;
        for(int j=i;j<n-1;j++){
            ans=min(ans,f(j+1,k-1,s,cost)+cost[i][j]);
        }
        return dp[i][k]=ans;
    }
    int palindromePartition(string s, int k) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>cost(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            string curr="";
            for(int j=i;j<n;j++){
                curr.push_back(s[j]);
                cost[i][j]=precomp(curr);
            }
        }
        return f(0,k-1,s,cost);
    }
};