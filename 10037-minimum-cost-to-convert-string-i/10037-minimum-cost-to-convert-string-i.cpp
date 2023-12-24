#define ll long long 
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long n=original.size();
        long long sz=source.size();
        vector<vector<pair<long long,long long>>>graph;
        map<pair<ll,ll>,ll>fre;
        for(int i=0;i<n;i++){
            fre[{original[i],changed[i]}]=cost[i];
        }
            vector<vector<ll>>dp(26,vector<ll>(26,1e12));
            for(int i=0;i<26;i++)dp[i][i]=0;
        for(ll i=0;i<n;i++){
            dp[original[i]-'a'][changed[i]-'a']=min(dp[original[i]-'a'][changed[i]-'a'],(ll)cost[i]);
        }
        for(ll k=0;k<26;k++){
            for(ll i=0;i<26;i++){
                for(ll j=0;j<26;j++){
                    if(dp[i][k]!=1e12 && dp[k][j]!=1e12 && dp[i][j]>dp[i][k]+dp[k][j]){
                        dp[i][j]=dp[i][k]+dp[k][j];
                    }
                }
            }
        }
        ll res=0;
        for(ll i=0;i<sz;i++){
            res+=dp[source[i]-'a'][target[i]-'a'];
        }
        if(res>=1e12)return -1;
        return res;
    }
};