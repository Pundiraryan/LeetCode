class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans=0;
        set<int>midx;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(midx.size()!=n){
            if(pq.empty())break;
            auto pr=pq.top();
            pq.pop();
            if(midx.find(pr.second)!=midx.end())continue;
            ans+=(long long)pr.first;
            int idx=pr.second;
            midx.insert(idx);
            if(idx>0)midx.insert(idx-1);
            if(idx<n-1)midx.insert(idx+1);
        }
        return ans;
    }
};