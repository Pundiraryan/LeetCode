class DSU{
    vector<int>parent;
    vector<int>sz;
    public:
    DSU(int n){
        parent.resize(n+1);
        sz.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int findpar(int i){
        if(parent[i]==i)return i;
        return parent[i]=findpar(parent[i]);
    }
    void join(int a,int b){
        a=findpar(a);
        b=findpar(b);
        // if(a==b)return false
        if(a!=b){
            if(sz[a]>sz[b])swap(a,b);
            parent[a]=b;
            sz[b]+=sz[a];
        }
        // return true;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // sort(edges.rbegin(),edges.rend());
        int ans=0;
        DSU d1(n),d2(n);
        for(auto &x:edges){
            if(x[0]==3){
                if(d1.findpar(x[1])==d1.findpar(x[2])  && d2.findpar(x[1])==d2.findpar(x[2]))ans++;
                if(d1.findpar(x[1])!=d1.findpar(x[2]))d1.join(x[1],x[2]);
                if(d2.findpar(x[1])!=d2.findpar(x[2]))d2.join(x[1],x[2]);
            }
        }
        for(auto &x:edges){
            if(x[0]==1){
                // cout<<" in t1 \n";
                // cout<<d1.findpar(x[1])<<" || "<<d1.findpar(x[2]);
                if(d1.findpar(x[1])==d1.findpar(x[2]))ans++;
                else d1.join(x[1],x[2]);
            }else if(x[0]==2){
                // cout<<" in t2 \n";
                // cout<<d2.findpar(x[1])<<" || "<<d2.findpar(x[2]);
                if(d2.findpar(x[1])==d2.findpar(x[2]))ans++;
                else d2.join(x[1],x[2]);
            }
        }
        int d1upar=d1.findpar(1),d2upar=d2.findpar(1);
        for(int i=1;i<=n;i++){
            if(d1upar!=d1.findpar(i))return -1;
        }
        for(int i=1;i<=n;i++){
            if(d2upar!=d2.findpar(i))return -1;
        }
        return ans;
    }
};