class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ax=0;
        for(auto &x:nums)ax^=x;
        int ssb=0;
        for(int i=0;i<31;i++){
            if((ax>>i)&1){
             ssb=i;break;   
            }
        }
        int n1=0,n2=0;
        for(auto &x:nums){
            if((x>>ssb)&1)n1^=x;
            else n2^=x;
        }
        return {n1,n2};
    }
};