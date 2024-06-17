class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans=0;
        long long curr=0;
        int i=0;
        while(curr<n){
             if(i<nums.size() && nums[i]<=curr+1){
                     curr+=nums[i++];
                }else{
                    ans++;
                  curr*=2;
                  curr++;
                }
        }
        return ans;
    }
};