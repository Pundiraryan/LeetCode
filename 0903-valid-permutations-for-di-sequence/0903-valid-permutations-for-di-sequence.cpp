#define mod 1000000007
class Solution {
public:
    long long dp[205][205];
    long long f(int i,int prev,string &s,vector<int>&done){
        if(i==s.length())return 1;
        long long ans=0;
        if(dp[i][prev]!=-1)return dp[i][prev];
        if(s[i]=='D'){
            for(int j=0;j<prev;j++){
                if(!done[j]){
                    done[j]=1;
                    ans=(ans+f(i+1,j,s,done))%mod;
                    done[j]=0;
                }
            }
        }else{
            for(int j=prev+1;j<=s.length();j++){
                 if(!done[j]){
                    done[j]=1;
                    ans=(ans+f(i+1,j,s,done))%mod;
                    done[j]=0;
                }
            }
        }
        return dp[i][prev]=ans;
    }
    int numPermsDISequence(string s) {
        int n=s.length();
        long long res=0;
        memset(dp,-1,sizeof(dp));
        vector<int>done(n+1,0);
        for(int i=0;i<=n;i++){
            done[i]=1;
            res=(res+f(0,i,s,done))%mod;
            done[i]=0;
        }
        return res;
    }
};