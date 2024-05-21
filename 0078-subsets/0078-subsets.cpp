class Solution {
public:
    void gen(int i,vector<int>&curr,vector<int>&nums,vector<vector<int>>&res){
        int n=nums.size();
        if(i==n){
            res.push_back(curr);
            return;
        }
        gen(i+1,curr,nums,res);
        curr.push_back(nums[i]);
        gen(i+1,curr,nums,res);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        gen(0,curr,nums,ans);
        return ans;
    }
};