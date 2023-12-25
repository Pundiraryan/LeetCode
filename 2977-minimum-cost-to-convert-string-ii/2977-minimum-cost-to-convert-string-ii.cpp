#define ll long long
class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string,ll>hash;
        for(auto &x:original){
            if(hash.find(x)==hash.end())hash[x]=hash.size();
        }
        for(auto &x:changed){
            if(hash.find(x)==hash.end())hash[x]=hash.size();
        }
        ll n=hash.size();
        // cout<<"here";
        vector<vector<ll>>dp1(n,vector<ll>(n,LONG_MAX));
        for(ll i=0;i<n;i++)dp1[i][i]=0;
        for(ll i=0;i<cost.size();i++){
           ll from=hash[original[i]];
            ll to=hash[changed[i]];
            // cout<<from<<"----"<<to<<endl;
            dp1[from][to]=min(dp1[from][to],(ll)cost[i]);
        }
        // cout<<"out1";
        for(ll k=0;k<n;k++){
            for(ll i=0;i<n;i++){
                for(ll j=0;j<n;j++){
                    if(dp1[i][k]!=LONG_MAX && dp1[k][j]!=LONG_MAX && dp1[i][j]>dp1[i][k]+dp1[k][j]){
                        dp1[i][j]=dp1[i][k]+dp1[k][j];
                    }
                }
            }
        }
        //consider only the unique lenghts in original array to avoid tle
        unordered_set<ll>ul;
        for(auto &x:original)ul.insert(x.length());
        vector<ll>dp(target.size()+1,LONG_MAX);
        dp[0]=0;
        // cout<<"here";
        //dp[i]- cost to convert length i of source string to target string
        for(ll i=0;i<target.size();i++){
            if(dp[i]==LONG_MAX)continue;
            if(source[i]==target[i]){
                dp[i+1]=min(dp[i+1],dp[i]);
            }
            for(auto &len:ul){
                if(i+len>=dp.size())continue;
                string from=source.substr(i,len);
                string to=target.substr(i,len);
                int hv1=-1,hv2=-1;
                if(hash.find(from)!=hash.end())hv1=hash[from];
                if(hash.find(to)!=hash.end())hv2=hash[to];
                if(hv1>=0 && hv2>=0 && dp1[hv1][hv2]<LONG_MAX ){
                    dp[i+len]=min(dp[i+len],dp[i]+dp1[hv1][hv2]);
                }
            }
        }
        if(dp[dp.size()-1]==LONG_MAX)return -1;
        return dp[dp.size()-1];
    }
};