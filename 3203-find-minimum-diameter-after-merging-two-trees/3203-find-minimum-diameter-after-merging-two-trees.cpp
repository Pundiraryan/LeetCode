class Solution {
public:
    void dfs(int src,int parent,vector<vector<int>>&tree,vector<int>&dn){
    for(int x:tree[src]){
        if(x==parent)continue;
        dn[x]=1+dn[src];
        dfs(x,src,tree,dn);
    }
}
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1,m=edges2.size()+1;
        vector<vector<int>>graph1(n),graph2(m);
        for(auto &x:edges1){
            graph1[x[0]].push_back(x[1]);
            graph1[x[1]].push_back(x[0]);
        }
        for(auto &x:edges2){
            graph2[x[0]].push_back(x[1]);
            graph2[x[1]].push_back(x[0]);
        }
        vector<int>dn1(n);
        dfs(0,-1,graph1,dn1);
        int mdn=-1,maxd=-1;
        for(int i=0;i<n;i++){
            if(dn1[i]>maxd){
                maxd=dn1[i];
                mdn=i;
            }
            dn1[i]=0;
        }
        dfs(mdn,-1,graph1,dn1);
        maxd=-1;
        for(int i=0;i<n;i++){
            if(dn1[i]>maxd){
                maxd=dn1[i];
            }
        }
        int dm1=maxd;
        vector<int>dn2(m);
        dfs(0,-1,graph2,dn2);
        mdn=-1,maxd=-1;
        for(int i=0;i<m;i++){
            if(dn2[i]>maxd){
                maxd=dn2[i];
                mdn=i;
            }
            dn2[i]=0;
        }
        dfs(mdn,-1,graph2,dn2);
        maxd=-1;
        for(int i=0;i<m;i++){
            if(dn2[i]>maxd){
                maxd=dn2[i];
            }
        }
        int dm2=maxd;
        return max({dm1,dm2,1+(dm1+1)/2+(dm2+1)/2});
    }
};