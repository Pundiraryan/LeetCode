class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ma=*max_element(nums.begin(),nums.end());
        int ans=0,cnt=0;
        for(auto &x:nums){
            if(x>=ma)cnt++;
            else{
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};