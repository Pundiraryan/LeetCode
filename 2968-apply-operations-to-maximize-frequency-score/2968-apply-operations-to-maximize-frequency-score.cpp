#define ll long long
class Solution {
public:
    bool checker(vector<int>&nums,vector<ll>&ps,int l,int r,ll k){
        long long m=(l+r)/2;
        long long desired=ps[r]-2*ps[m]+(l>0? ps[l-1]: 0);
        long long req=nums[m]*(2*m-r-l+1);
        long long ans=desired+req;
        return ans<=k;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
         sort(nums.begin(), nums.end());
        int n=nums.size();
        // long long sum=0;
        vector<long long> ps(n);
        ps[0]=nums[0];
        for(int i=1; i<n; i++)ps[i]=ps[i-1]+nums[i];
        int ans=0;
        int r=0, l=0;
        while(r<nums.size()){
            if(checker(nums, ps, l, r, k))
            ans=max(ans, r-l+1), r++;
        else l++;
        }
        return ans;
    }
};