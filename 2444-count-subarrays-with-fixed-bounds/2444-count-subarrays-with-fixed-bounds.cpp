class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int fidx=-1,mnidx=-1,mxidx=-1,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==minK)mnidx=i;
            if(nums[i]==maxK)mxidx=i;
            if(nums[i]<minK ||  nums[i]>maxK){
                fidx=i;
                mnidx=-1;mxidx=-1;
            }
            if(mnidx!=-1 && mxidx!=-1){
                ans+=max(0,min(mxidx,mnidx)-fidx);
            }
        }
        return ans;
        
    }
};