#define ll long long
class Solution {
public:
    vector<int> seive(int n){
        vector<int>primes(n+1,true);
        primes[1]=false;
        for(int i=2;i*i<=n;i++){
            if(primes[i]){
                for(int j=2*i;j<=n;j+=i)primes[j]=false;
            }
        }
        return primes;
    }
    pair<ll,ll> dfs(int node,int par,vector<vector<int>>&graph,ll &ans,vector<int>&primes){
        pair<int,int>p10={0ll,0ll};
        if(primes[node])p10.first=1;
        else p10.second=1;
        for(auto &x:graph[node]){
            if(x==par)continue;
            pair<int,int>c10=dfs(x,node,graph,ans,primes);
            ans+=(p10.first*c10.second+p10.second*c10.first);
            if(primes[node])p10.first+=c10.second;
            else{
                p10.first+=c10.first;
                p10.second+=c10.second;
            }
        }
        return p10;
    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        ll ans=0;
        vector<int>primes=seive(n);
        vector<vector<int>>graph(n+1);
        for(auto &x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        dfs(1,0,graph,ans,primes);
        return ans;
        
    }
};