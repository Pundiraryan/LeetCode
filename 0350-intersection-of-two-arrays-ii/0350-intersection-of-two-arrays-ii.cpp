class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>fre1,fre2;
        for(auto &x:nums1)fre1[x]++;
        for(auto &x:nums2)fre2[x]++;
        for(int i=0;i<1001;i++){
            int mf=min(fre1[i],fre2[i]);
            while(mf--)ans.push_back(i);
        }
        return ans;
    }
};