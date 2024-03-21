class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int,pair<int,int>>>vp;
        int n=aliceValues.size();
        for(int i=0;i<n;i++){
            vp.push_back({aliceValues[i]+bobValues[i],{aliceValues[i],bobValues[i]}});
        }
        sort(vp.begin(),vp.end());
        int as=0,bs=0;
        for(int i=n-1;i>=0;i-=2){
            as+=vp[i].second.first;
        }
        for(int i=n-2;i>=0;i-=2){
            bs+=vp[i].second.second;
        }
        if(as>bs)return 1;
        else if(as<bs)return -1;
        return 0;
    }
};