class Solution {
public:
    int largestCombination(vector<int>& nums) {
        vector<int>cnt(25,0);
                int ans=0;
        for(auto &x:nums){
            for(int i=0;i<25;i++){
                if((x>>i)&1)cnt[i]++;
                ans=max(ans,cnt[i]);
            }
        }
            return ans;
    }
};