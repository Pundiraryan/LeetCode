class DSU{
    public:
    vector<int>parent;
    vector<int>sz;
    DSU(int n){
        sz.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int val){
        if(parent[val]==val)return val;
        return parent[val]=find(parent[val]);
    }
    void join(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(sz[a]>sz[b])swap(a,b);
            sz[b]+=sz[a];
            parent[a]=b;
        }
    }
};
class Solution {
public:
    vector<int>spf;
    void precomp(){
        spf[1] = 1;
        int n=spf.size();
        for (int i = 2; i < n; i++)spf[i] = i;
        for (int i = 4; i <n; i += 2)spf[i] = 2;
        for (int i = 3; i * i < n; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < n; j += i)
                    if (spf[j] == j)spf[j] = i;
            }
        }
    }
    vector<int> factorize(int x)
    {
        vector<int> ret;
        while (x != 1) {
            ret.push_back(spf[x]);
            x = x / spf[x];
        }
        return ret;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        int maxn=*max_element(nums.begin(),nums.end());
        spf.resize(maxn+1);
        vector<pair<int,int>>graph;
        DSU d(maxn);
        precomp();
        for(auto &x:nums){
            if(x==1)return false;
            vector<int>pf=factorize(x);
            for(auto &f:pf){
                graph.push_back({x,f});
                graph.push_back({f,x});
            }
        }
        for(auto &x:graph){
            d.join(x.first,x.second);
        }
        unordered_set<int>up;
        for(auto &x:nums){
            up.insert(d.find(x));
        }
        return up.size()==1;
        
        
        
    }
};