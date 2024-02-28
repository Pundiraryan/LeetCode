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
 void sieve(int n)
{
    spf[1] = 1;
    for(int i=2;i<n;i++)spf[i]=i;
        for(int i=2;i*i<n;i++)
        {
            if(spf[i]==i)
            {
                for(int j=i*i;j<n;j+=i)
                {
                    if(spf[j]>i)spf[j]=i;
                }
            }
        }
}
 
vector<int> factorise(int x)
{
    vector<int>ret;
    while (x> 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
    bool gcdSort(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        spf.resize(maxi+5);
        sieve(maxi+2);
        DSU d(maxi+1);
        for(int i=0;i<n;i++){
            vector<int>factors=factorise(nums[i]);
            for(auto &y:factors){
                d.join(nums[i],y);
            }
        }       
        vector<int>nnums=nums;
        sort(nnums.begin(),nnums.end());
        for(int i=0;i<n;i++){
            if(d.find(nums[i])!=d.find(nnums[i])){
                return false;
            }
        }
        return true;
    }
};