class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=0;
        for(auto &x:nums)sum+=x;
        long long reqd=abs(goal-sum);
        if(reqd%limit==0)return reqd/limit;
        return (reqd/limit) +1;
        
    }
};