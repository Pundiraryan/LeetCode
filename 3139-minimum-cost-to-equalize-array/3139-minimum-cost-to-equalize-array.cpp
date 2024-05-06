#define ll long long
#define mod 1000000007
class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        ll n=nums.size();
        ll mxv=*max_element(nums.begin(),nums.end());
        ll mnv=*min_element(nums.begin(),nums.end());
        ll sv=accumulate(nums.begin(),nums.end(),0ll);
        ll ans=1e18;
        if(n==2 || 2*cost1<=cost2){
            ll res=(n*mxv -sv);
            res=(res*cost1)%mod;
            return res;
        }
        for(int lim=mxv;lim<=2*mxv;lim++){
            ll tot=n*lim-sv;
            ll other=lim-mnv;
            ll baki=tot-other;
            if(other>baki){
                ll c1wale=other-baki;
                ll c2wale=baki;
                ll cost=c2wale*cost2+c1wale*cost1;
                ans = min(ans,cost);
            }
            else{
                ll c2wale=tot/2;
                ll c1wale=(tot&1);
                 ll cost=c2wale*cost2+c1wale*cost1;
                ans = min(ans,cost);
            }
        }
        return ans%mod;
    }
};