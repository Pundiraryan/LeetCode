class Solution {
public:
    int ans;
    void f(int i,vector<int>&curr,vector<int>&nums){
        int n=nums.size();
        if(i==n)
        {
            int cx=0;
            for(auto &x:curr)cx^=x;
            ans+=cx;
            return;
        } 
        f(i+1,curr,nums);
        curr.push_back(nums[i]);
        f(i+1,curr,nums);
        curr.pop_back();
    }
    int subsetXORSum(vector<int>& nums) {
        ans=0;
        vector<int>curr;
        f(0,curr,nums);
        return ans;
    }
};