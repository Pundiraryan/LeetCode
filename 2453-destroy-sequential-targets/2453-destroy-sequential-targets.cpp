    class Solution {
    public:
        int destroyTargets(vector<int>& nums, int space) {
            unordered_map<int,int>fre;
            sort(nums.begin(),nums.end());
            for(auto &x:nums)fre[x%space]++;
            int mk=0,ans=1e9;
            for(auto &x:fre)mk=max(mk,x.second);
            unordered_set<int>st;
            for(auto &x:fre){
                if(x.second==mk)st.insert(x.first);
            }
            for(auto &x:nums){
                if(st.find(x%space)!=st.end()){
                    ans=min(ans,x);
                }
            }
            return ans;
        }
    };