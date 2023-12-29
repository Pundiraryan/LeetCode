class Solution {
public:
    int cnt(vector<int>&nums1,vector<int>&nums2){
        int ans=0,n=nums1.size();
        for(int i=0;i<n;i++){
            if(nums1[i]<=nums1[n-1] && nums2[i]<=nums2[n-1])continue;
            else if(nums1[i]<=nums2[n-1] && nums2[i]<=nums1[n-1])ans++;
            else return -1;
        }
        return ans;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        if(n==1)return 0;
        int ans=1e9;
        int curr=cnt(nums1,nums2);
        if(curr+1){
            ans=min(ans,curr);
        }
        swap(nums1[n-1],nums2[n-1]);
        curr=cnt(nums1,nums2);
        if(curr+1){
            ans=min(ans,curr+1);
        }
        if(ans==1e9)return -1;
        return ans;
    }
};