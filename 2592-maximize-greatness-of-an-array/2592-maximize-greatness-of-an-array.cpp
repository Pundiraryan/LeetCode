class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        while(j<n){
            while( j<n && nums[j]<=nums[i])j++;
            if(j==n)break;
            ans++;
            i++;j++;
        }
        return ans;
    }
};