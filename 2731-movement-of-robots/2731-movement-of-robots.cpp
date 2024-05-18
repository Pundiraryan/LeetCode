#define mod 1000000007
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        // collision doesnt matter
        int n=nums.size();
        vector<long long>posf(n);
        for(int i=0;i<n;i++){
            if(s[i]=='L')posf[i]=(long long)nums[i]-d;
            else posf[i]=(long long)nums[i]+d;
        }
        sort(posf.begin(),posf.end());
        long long sv=0;
        long long int ans=0;
        for(int i=0;i<n;i++){
            long long val=(long long)posf[i]*i;
            val-=sv;
            ans=(long long)(ans+val)%mod;
            sv+=(long long)posf[i];
        }
        return ans;
    }
};