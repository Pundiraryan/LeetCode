#define lvl 17
#define maxn 50005
class TreeAncestor {
public:
    int par[maxn][lvl];
    void precomp(int n) 
    { 
        for (int i=1; i<lvl; i++) 
        { 
            for (int node = 0; node < n; node++) 
            { 
                if (par[node][i-1] != -1) 
                    par[node][i] = 
                        par[par[node][i-1]][i-1]; 
            } 
        } 
    } 
    TreeAncestor(int n, vector<int>& parent) {
        memset(par,-1,sizeof(par));
        for(int i=0;i<n;i++){
            par[i][0]=parent[i];
        }
        precomp(n);
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<lvl;i++){
            if((k>>i)&1){
                if(node==-1)break;
                node=par[node][i];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */