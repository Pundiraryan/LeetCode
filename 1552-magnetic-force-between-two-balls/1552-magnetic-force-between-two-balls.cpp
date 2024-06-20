class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        int l=0,r=2e9,ans=r;
        sort(position.begin(),position.end());
        auto check=[&](int mid)->bool{
            int i=0;
            int tv=m;
            while(i<n && tv>0){
                i=lower_bound(position.begin(),position.end(),mid+position[i])-position.begin();
                tv--;
            }
            if(tv>0)return false;
            return true;
        };
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};