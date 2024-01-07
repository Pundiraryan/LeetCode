class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_set<int>st1,st2;
        for(auto &x:nums1)st1.insert(x);
        unordered_set<int>common;
        for(auto &x:nums2){
            if(st1.find(x)!=st1.end()){
                common.insert(x);
            }
            st2.insert(x);
        }
        int cnt1=st1.size(),cnt2=st2.size(),comm=common.size();
        return min(n,min(n/2,cnt1-comm)+min(n/2,cnt2-comm)+comm);
        
    }
};