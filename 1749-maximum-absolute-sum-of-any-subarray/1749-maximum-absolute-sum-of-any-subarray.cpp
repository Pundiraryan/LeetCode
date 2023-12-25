class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int csum=0,csum1=0,ans=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++){
            csum+=nums[i];
            if(csum<0)csum=0;
            csum1+=nums[i];
            if(csum1>0)csum1=0;
            ans=max(ans,max(csum,-csum1));
        }
        return ans;
    }
};