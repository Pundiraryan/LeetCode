#define ll long long
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<ll,int>lt,rt;
        ll sum=0;
        for(auto &x:nums)sum+=x;
        ll cs=0;
        for(int i=0;i<n-1;i++){
            cs+=(ll)nums[i];
            ll rs=sum-cs;
            rt[cs-rs]++;
        }
        int ans=rt[0];
        ll ls=0;
        for(int i=0;i<n;i++){
            ll diff=k-nums[i];
            ans=max(ans,rt[-diff]+lt[diff]);
            ls+=(ll)nums[i];
            ll rs=sum-ls;
            lt[ls-rs]++;
            rt[ls-rs]--;
            if(rt[ls-rs]==0){
                rt.erase(ls-rs);
            }
        }
        return ans;
    }
};