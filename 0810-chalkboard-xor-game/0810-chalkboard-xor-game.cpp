class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int ax=0;
        for(auto &x:nums)ax^=x;
        return (!ax || nums.size()%2==0);
    }
};