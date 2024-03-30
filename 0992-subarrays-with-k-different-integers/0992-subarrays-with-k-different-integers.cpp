class Solution {
public:
    int f(vector<int>&nums,int k){
        int n=nums.size(),i=0,j=0,cnt=0;
        unordered_map<int, int>fre;
        while(j<n){
            fre[nums[j]]++;
            while(fre.size()>k){
                fre[nums[i]]--;
                if(fre[nums[i]]==0)fre.erase(nums[i]);
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};