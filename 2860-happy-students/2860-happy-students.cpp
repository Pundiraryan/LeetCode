class Solution {
public:
    int countWays(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res=0;
        if(nums[0]>0)res++;
        for(int i=0;i<n-1;i++){
            if(i+1>nums[i] && nums[i+1]>i+1){
                res++;
            }
        }
        if(nums[n-1]<n)res++;
        return res;
    }
};