#define ll long long
class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        set<int>st;
        for(auto &x:nums)st.insert(x);
        ll l = 1, r = (ll)st.size(), ans = 1;
        ll tv=(ll)n *(n + 1)/2;
        ll mc=(tv+1)/2;
        auto check=[&](ll mid)->bool{
            ll i=0,j=0;
            ll res = 0;
            unordered_map<int, ll>fre;
            while(j<n){
                fre[nums[j]]++;
                while(fre.size()>mid){
                    fre[nums[i]]--;
                    if(fre[nums[i]]==0){
                        fre.erase(fre.find(nums[i]));
                    }
                    i++;
                }
                res+=(j-i+1);
                j++;
            }
            return  res>=mc;
        };
            
        while (l<=r) {
            ll mid = (l+r)/ 2;
            if (check(mid)) {
                ans = mid;
                r=mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};