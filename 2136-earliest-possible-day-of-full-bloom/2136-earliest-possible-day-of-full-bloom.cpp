class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int sum=0;
        vector<pair<int,int>>vp;
        for(int i=0;i<plantTime.size();i++){
            vp.push_back({growTime[i],plantTime[i]});
        }
        sort(vp.begin(),vp.end());
        int ans=0;
        int pt=0;
        for(int i=plantTime.size()-1;i>=0;i--){
            pt+=vp[i].second;
            ans=max(ans,pt+vp[i].first);
        }
        return ans;
    }
};