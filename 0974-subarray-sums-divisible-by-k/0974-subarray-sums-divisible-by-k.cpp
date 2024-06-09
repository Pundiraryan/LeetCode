class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>fre;
        fre[0]=1;
        int cs=0;
        int ans=0;
        for(auto &x:nums){
            cs=(cs+x%k+k)%k;
            ans+=fre[cs];
            fre[cs]++;
        }
        return ans;
    }
};