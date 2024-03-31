class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int i=0,j=0;
        while(j<n){
            int i=j+1;
            while(i<n && nums[i]!=nums[i-1]){
                i++;
            }
            ans+=((long long)(i-j+1)*(long long)(i-j))/2;
            j=i;
        }
        return ans;
    }
};