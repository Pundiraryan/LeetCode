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
    
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        int maxn=*max_element(nums.begin(),nums.end());
        DSU d(maxn);
        for(auto &x:nums){
           for(int i=2;i*i<=x;i++){
               if(x%i==0){
                   d.join(x,i);
                   d.join(x,x/i);
               }
           }
        }
        unordered_map<int,int>fre;
        int res=0;
        for(auto &x:nums){
            fre[d.find(x)]++;
            res=max(res,fre[d.find(x)]);
        }
        return res;
    }
};