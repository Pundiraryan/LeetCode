class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto &x:nums)pq.push(x);
        int ans=0;
        while(pq.size()>=2){
            long long mn=pq.top();pq.pop();
            if(mn>=k)break;
            long long smn=pq.top();pq.pop();
            long long val=(long long)2*mn+(long long)smn;
            pq.push(val);
            ans++;
        }
        return ans;
    }
};