class DSU{
    public:
    vector<int>parent,sz;
    DSU(int n){
        parent.resize(n+1);
        sz.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int find(int val){
        if(val==parent[val])return val;
        return parent[val]=find(parent[val]);
    }
    void join(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(sz[a]>sz[b])swap(a,b);
            parent[a]=b;
            sz[b]+=sz[a];
        }
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        string ans="";
        int n=s.length();
        DSU d(n);
        for(auto &x:pairs)d.join(x[0],x[1]);
        map<int,multiset<char>>fre;
        for(int i=0;i<n;i++){
            fre[d.find(i)].insert(s[i]);
        }
        for(int i=0;i<n;i++){
           auto it=fre[d.find(i)].begin();
           ans.push_back(*it);
           fre[d.find(i)].erase(it);
        }
        return ans;
    }
};