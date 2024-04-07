class Solution {
public:
    int dp[105][105];
    int f(int i,int diff,string &s){
        int n=s.length();
        if(i==n){
            if(diff==0)return 1;
            return 0;
        }
        if(dp[i][diff]!=-1)return dp[i][diff];
        int ans=0;
        if(s[i]=='(')ans=f(i+1,diff+1,s);
        else if(s[i]==')'){
            if(diff)ans=f(i+1,diff-1,s);
        }
        else{
            ans|=f(i+1,diff+1,s);
            if(diff)ans|=f(i+1,diff-1,s);
            ans|=f(i+1,diff,s);
        }
        return dp[i][diff]=ans;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return (bool)f(0,0,s);
    }
};