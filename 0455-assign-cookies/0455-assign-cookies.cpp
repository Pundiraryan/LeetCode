class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(),c=s.size();
        sort(g.begin(),g.end());
        multiset<int>ca;
        int ans=0;
        for(auto &x:s)ca.insert(x);
        for(int i=0;i<n;i++){
            if(ca.empty())break;
            auto it=ca.lower_bound(g[i]);
            if(it!=ca.end()){
                ans++;
                 ca.erase(it);
            }
        }
        return ans;
    }
};