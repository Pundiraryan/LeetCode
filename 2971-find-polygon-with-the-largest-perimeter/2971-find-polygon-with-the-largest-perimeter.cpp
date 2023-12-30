#define ll long long
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ll ans=-1;
        sort(nums.begin(),nums.end());
        ll  maxi=nums[2],rs=nums[0]+nums[1];
        if(rs>maxi)ans=rs+maxi;
        ll i=0,j=3;
        ll n=nums.size();
        while(j<n){
            maxi=nums[j];
            rs+=nums[j-1];
            if(rs>maxi){
                cout<<rs<<" "<<maxi<<endl;
                if(j-i>=2)ans=max(ans,rs+maxi);
            }
            j++;
        }
        return ans;
    }
};