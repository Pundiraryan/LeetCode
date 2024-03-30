class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0,cnt=0;
        int i=0,j=0;
        int n=nums.size();
        unordered_map<int,int>fre;
        while(j<n){
            fre[nums[j]]++;
            cnt+=(fre[nums[j]]-1);
            while(i<j && cnt>=k){
                ans+=(n-j);
                fre[nums[i]]--;
                cnt-=fre[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};