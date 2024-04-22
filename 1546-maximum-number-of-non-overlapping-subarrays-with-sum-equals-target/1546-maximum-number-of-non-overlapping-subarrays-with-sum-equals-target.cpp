class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int ans=0,cs=0;
        int n=nums.size();
        unordered_map<int,int>fre;
        fre[0]=1;
        for(auto &x:nums){
            cs+=x;
            if(fre.find(cs-target)!=fre.end()){
                ans++;
                fre.clear();
            }
            fre[cs]++;
        }
        return ans;
    }
};