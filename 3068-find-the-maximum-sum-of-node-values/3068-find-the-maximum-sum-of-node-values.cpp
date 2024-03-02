class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans=0;
        long long minnotxor=1e9+5;
        long long profit=0;
        for(auto &x:nums){
            if((x^k) >x){
                ans+=x^k;
                profit++;
            }else{
                ans+=x;
            }
            minnotxor=min(minnotxor,(long long)abs((x^k) -x));
        }
        if(profit%2==1)ans-=minnotxor;
        return ans;
    }
};