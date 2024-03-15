class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        map<int,long long>fre;
        for(int i=0;i<n;i++)fre[edges[i]]+=i;
        int ans=-1,ansn=-1;
        for(auto &x:fre){
            if(x.second>ans){
                ansn=x.first;
                ans=x.second;
            }
        }
        return ansn;
    }
};