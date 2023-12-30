#define ll long long
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll sum1=0,count1=0,sum2=0,count2=0;
        ll n=nums1.size(),m=nums2.size();
        ll ans=-1;
        for(ll i=0;i<n;i++){
            if(nums1[i]==0)count1++;
            sum1+=nums1[i];
        }
        for(ll i=0;i<m;i++){
            if(nums2[i]==0)count2++;
            sum2+=nums2[i];
        }
        if(count1 != 0 && count2 != 0) ans = max(sum1 + count1, sum2 + count2);
    else if(count1 == 0 && count2 != 0 && (sum1 >= sum2 + count2) ) ans = sum1;
    else if(count2 == 0 && count1 != 0 && (sum2 >= sum1 + count1) ) ans = sum2;
    else if(count2 == 0 && count1 == 0 && sum1 == sum2) ans = sum1;
    return ans;
    }
};