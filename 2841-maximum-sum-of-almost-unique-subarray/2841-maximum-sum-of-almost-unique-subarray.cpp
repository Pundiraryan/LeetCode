class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans=0,cs=0;
        set<int>st;
        int n=nums.size();
        unordered_map<int,int>fre;
        for(int i=0;i<k;i++){
            fre[nums[i]]++;
            cs+=nums[i];
        }
        if(fre.size()>=m){
            ans=max(ans,cs);
        }
        for(int i=k;i<n;i++){
            fre[nums[i-k]]--;
            if(fre[nums[i-k]]==0)fre.erase(fre.find(nums[i-k]));
            fre[nums[i]]++;
            cs-=nums[i-k];
            cs+=nums[i];
            if(fre.size()>=m){
                ans=max(ans,cs);
            }
        }
        return ans;
    }
};