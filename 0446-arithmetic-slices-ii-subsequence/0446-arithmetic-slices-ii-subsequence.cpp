#define ll long long int
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<ll,ll>>dp(n);
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff=1ll*nums[i]-1ll*nums[j];
                if(diff>INT_MAX || diff<INT_MIN)continue;
                ll curr=0;
                if(dp[j].find(diff)!=dp[j].end())curr=dp[j][diff];
                dp[i][diff]+=(curr+1);
                res+=curr;
            }
        }
        return res;
    }
};