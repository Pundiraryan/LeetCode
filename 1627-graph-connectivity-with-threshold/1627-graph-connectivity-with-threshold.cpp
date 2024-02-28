
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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU d(n);
       for(int i=threshold+1;i<=n;i++){
           for(int j=2;j*i<=n;j++){
               d.join(i,j*i);
           }
       }
        vector<bool>ans(queries.size(),true);
        if(!threshold)return ans;
        for(int i=0;i<queries.size();i++){
            if(d.find(queries[i][0])!=d.find(queries[i][1])){
                ans[i]=false;
            }
        }
        return ans;
    }
};