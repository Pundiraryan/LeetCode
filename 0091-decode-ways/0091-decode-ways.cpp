class Solution {
public:
    int dp[105];
    int f(int i,int n,string &s){
        if(i==n)return 1;
         if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=f(i+1,n,s);
        if(i==n-1)return dp[i]=ans;
        if(s[i]=='1' && s[i+1]>='0' && s[i+1]<='9'){
            ans+=f(i+2,n,s);
        }
        if(s[i]=='2' && s[i+1]>='0' && s[i+1]<='6'){
            ans+=f(i+2,n,s);
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return f(0,s.length(),s);
    }
};