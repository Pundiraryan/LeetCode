class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int allxor=0;
       for(auto &x:nums)allxor^=x;
        int res=0;
        for(int  i=20;i>=0;i--){
            res+=(((k>>i)&1)!=((allxor>>i)&1));
        }
        return res;
        int ans=0;
    }
};