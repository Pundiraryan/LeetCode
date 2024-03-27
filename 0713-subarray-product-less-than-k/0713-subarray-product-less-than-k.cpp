class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k<=1)return 0;
        int ans=0,cp=1,j=0,i=0;
        while(j<n){
            cp*=nums[j];
            while(cp>=k){
                cp/=nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};