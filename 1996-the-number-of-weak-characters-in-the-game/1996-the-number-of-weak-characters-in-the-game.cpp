bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first)return a.second<b.second;
    return a.first>b.first;
}
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        vector<pair<int,int>>vp;
        for(auto &x:p){
            vp.push_back({x[0],x[1]});
        }
        sort(vp.begin(),vp.end(),cmp);
        int ans=0;
        int mv=-1e9;
        for(int i=0;i<vp.size();i++){
            if(vp[i].second<mv)ans++;
            else {
                mv=vp[i].second;
            }
        }
        return ans;
    }
};