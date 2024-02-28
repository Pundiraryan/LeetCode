#define mod 1000000007
class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.length();
        vector<vector<int>>dp(s.length()+1,vector<int>(26,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<26;j++){
                if(s[i]-'a' !=j){
                    dp[i][j]=dp[i+1][j]%mod;
                }else{
                    int ans=1;
                    for(int k=0;k<26;k++){
                        ans=(ans+dp[i+1][k])%mod;
                    }
                    dp[i][j]=ans;
                }
            }
        }
        int res=0;
        for(int i=0;i<26;i++){
            res=(res+dp[0][i])%mod;
        }
        return res;
    }
};