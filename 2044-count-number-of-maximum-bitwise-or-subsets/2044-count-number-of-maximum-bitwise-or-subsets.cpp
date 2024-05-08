class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mor=0;
        int n=nums.size();
        for(auto &x:nums)mor|=x;
        int ans=0;
        for(int mask=0;mask<(1<<n);mask++){
            int cor=0;
            for(int i=0;i<n;i++){
                if((mask>>i)&1)cor|=nums[i];
            }
            ans+=(cor==mor);
        }
        return ans;
    }
};