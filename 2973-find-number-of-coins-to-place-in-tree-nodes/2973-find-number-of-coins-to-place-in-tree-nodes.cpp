class Solution {
public:
    #define ll long long 
    unordered_map<ll,vector<ll>>mp;
    unordered_map<ll,ll>mp1;
    unordered_map<ll,ll>ans;
    
    ll dfs(ll node,ll par,vector<int>&cost){
       
        ll s=0;
        for(auto it:mp[node]){
            if(it!=par){
               
              s+=dfs(it,node,cost);
            }
        }
        s++;
        mp1[node]=s;
        return s;
    }
    
    vector<ll> dfs2(ll node,ll parent,vector<int>&cost){
    
        vector<ll> v;
        vector<ll> k;
         v.push_back(cost[node]);
        for(auto it: mp[node]){
           if(it!=parent){
           vector<ll> x=dfs2(it,node,cost);
              
               for(auto it: x){
                   k.push_back(it);
               }
               
            
               }
         
           }
        if(v.size()<3){
            for(auto it: k){
                v.push_back(it);
            }
        }
        else {
            sort(k.begin(),k.end(),greater<int>());
            v.push_back(k[0]);
            v.push_back(k[1]);
            v.push_back(k[2]);
            v.push_back(k[k.size()-1]);
            v.push_back(k[k.size()-2]);
        }
         sort(v.begin(),v.end(),greater<ll>());

        
        if(mp1[node]<3){
            ans[node]=1;
        }
            
        else{
            ll p1=v[0]*v[1]*v[2]*1LL;
            ll p2=v[0]*v[v.size()-1]*v[v.size()-2]*1LL;
            ll p3=max(p1,p2);
            if(p3<0){
                ans[node]=0;
            }
            else{
                ans[node]=p3;
            }
        }
    if(v.size()<=5)return v;
       
        return {v[0],v[1],v[2],v[v.size()-1],v[v.size()-2]};
    }
    
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
       for(auto it: edges){
           mp[it[0]].push_back(it[1]);
           mp[it[1]].push_back(it[0]);
       }
        dfs(0,-1,cost);
        
        dfs2(0,-1,cost);
        vector<ll> c;
        for(int i=0;i<cost.size();i++){
            c.push_back(ans[i]);
        }
        return c;
        
    }
};