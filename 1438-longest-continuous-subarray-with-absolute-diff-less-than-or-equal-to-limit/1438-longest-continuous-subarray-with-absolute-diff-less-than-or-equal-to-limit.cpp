class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int i=0,j=0;
        int ans=0;
        multiset<int>mst;
        while(j<n){
            mst.insert(nums[j]);
            while(*mst.rbegin()-*mst.begin()>limit){
                mst.erase(mst.find(nums[i]));
                i++;
            }
            j++;
        ans=max(ans,(int)mst.size());
        }
        return ans;
    }
};