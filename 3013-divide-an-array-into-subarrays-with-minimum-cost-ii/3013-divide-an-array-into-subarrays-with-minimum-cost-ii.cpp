#define ll long long 
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll n=nums.size();
        ll cs=nums[0];
        multiset<ll>msl1,msl2;
        for(ll idx=1;idx<=dist+1;idx++){
            msl1.insert(nums[idx]);
            cs+=nums[idx];
        }
        while(msl1.size()>k-1){
            auto ridx=msl1.rbegin();
            cs-=*ridx;
            msl2.insert(*ridx);
            msl1.erase(msl1.find(*ridx));
        }
        ll ans=cs;
        for(int j=dist+2;j<n;j++){
           if(msl1.find(nums[j-dist-1])!=msl1.end()){
                cs-=nums[j-dist-1];
                msl1.erase(msl1.find(nums[j-dist-1]));
            }else{
                msl2.erase(msl2.find(nums[j-dist-1]));
            }
            if(nums[j]<*msl1.rbegin()){
                cs+=nums[j];
                msl1.insert(nums[j]);
            }else{
                msl2.insert(nums[j]);
            }
            while(msl1.size()<k-1){
                cs+=*(msl2.begin());
                msl1.insert(*(msl2.begin()));
                msl2.erase(msl2.begin());
            }
            while(msl1.size()>k-1){
                auto ridx=msl1.rbegin();
                cs-=*(ridx);
                msl2.insert(*ridx);
                msl1.erase(msl1.find(*ridx));
            }
            ans=min(ans,cs);
        }
        return ans;
    }
};