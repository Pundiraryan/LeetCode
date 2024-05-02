class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        unordered_map<long long,long long>fre;
        long long ans=0,cnt=0;
        fre[0]++;
        for(auto &x:nums){
            if(x%mod==k)cnt++;
            cnt%=mod;
            if(fre.find((cnt-k+mod)%mod)!=fre.end()){
                ans+=fre[(cnt-k+mod)%mod];
            }
            fre[cnt]++;
        }
        return ans;
    }
};