class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
       int ans=0;
        unordered_map<int,int>fre;
        for(auto &x:time){
            ans+=fre[(60-x%60)%60];
            fre[x%60]++;
        }
        return ans;
    }
};