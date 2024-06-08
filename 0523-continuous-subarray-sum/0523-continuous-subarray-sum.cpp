class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>fre;
        if(n==1)return false;
        fre[0]=-1;
        long long cs=0;
        for(int i=0;i<n;i++){
            cs=(cs+nums[i])%k;
            if(fre.find(cs)!=fre.end() && (i-fre[cs])>=2)return true;
            if(fre.find(cs)==fre.end())fre[cs]=i;
        }
        return false;
    }
};