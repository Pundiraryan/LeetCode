class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();
        v.push_back(0);
        int zc=0,oc=0;
        for(auto &x:nums){
            if(x==0)zc++;
            else oc++;
            v.push_back(oc-zc);
        }
        map<int,set<int>>fre;
        for(int i=0;i<v.size();i++)fre[v[i]].insert(i);
        int ans=0;
        for(auto &x:fre){
            set<int>st=x.second;
            ans=max(ans,*st.rbegin()-*st.begin());
        }
        return ans;
    }
};