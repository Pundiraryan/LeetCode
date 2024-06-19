class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size(),m=worker.size();
        int ans=0;
        vector<pair<int,int>>vp(n);
        for(int i=0;i<n;i++)vp[i]={difficulty[i],profit[i]};
        sort(vp.begin(),vp.end());
        vector<int>premax(n);
        premax[0]=vp[0].second;
        for(int i=1;i<n;i++)premax[i]=max(premax[i-1],vp[i].second);
        for(int i=0;i<m;i++){
            pair<int,int>pts={worker[i]+1,-1};
            int idx=lower_bound(vp.begin(),vp.end(),pts)-vp.begin();
            idx--;
            if(idx<0)continue;
            ans+=premax[idx];
        }
        return ans;
    }
};