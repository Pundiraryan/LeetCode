class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        int i=0;
        for(auto &x:nums)pq.push({x,i++});
        while(k--){
            long long val=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            long long nv=(long long)val*multiplier;
            pq.push({nv,idx});
        }
        vector<int>ans(n);
        while(!pq.empty()){
            ans[pq.top().second]=pq.top().first;
            pq.pop();
        }
        return ans;
    }
};