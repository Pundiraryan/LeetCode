#define ll long long
class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        ll n=nums1.size();
        ll ans=0;
        vector<ll>ok;
        unordered_map<ll,ll>fre;
        ll cnt=0;
        for(ll i=0;i<n;i++){
            if(nums1[i]!=nums2[i])ok.push_back(i);
            else{
                cnt++;
                ans+=i;
                fre[nums1[i]]++;
            }
        }
        if(fre.size()==0)return 0;
        ll majelem=-1;
        for(auto &x:fre){
            if(x.second>(cnt)/2){
                majelem=x.first;break;
            }
        }
        if(majelem!=-1){
            ll remfreq=2*fre[majelem]-cnt;
            for(auto &x:ok){
                if(nums1[x]!=majelem && nums2[x]!=majelem && remfreq>0){
                    remfreq--;
                    ans+=x;
                }
            }
            if(remfreq)return -1;
        }
        return ans;
    }
};