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
    int minScore(int n, vector<vector<int>>& roads) {
        DSU d(n+1);
        int ans=1e9;
        for(int i=0;i<roads.size();i++){
                d.join(roads[i][0],roads[i][1]);
        }
        int val=d.find(1);
        for(auto &x:roads){
            if(d.find(x[0])==val){
                ans=min(ans,x[2]);
            }
        }
        return ans;
    }
};