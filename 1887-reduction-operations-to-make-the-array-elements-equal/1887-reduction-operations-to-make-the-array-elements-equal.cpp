class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>fre;
        int pos=0;
        for(auto &x:nums){
            if(fre.find(x)==fre.end()){
                fre[x]=pos++;
            }
        }
        int ans=0;
        for(auto &x:nums)ans+=fre[x];
        return ans;
    }
};