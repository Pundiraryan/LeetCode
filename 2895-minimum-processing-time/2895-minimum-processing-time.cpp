class Solution {
public:
    int minProcessingTime(vector<int>& pt, vector<int>& t) {
        long long ans=2e9;
        long long l=0,r=ans;
        sort(pt.begin(),pt.end());
        sort(t.begin(),t.end());
        auto check=[&](int mid)->bool{
            long long i=0,j=t.size()-1;
            while(i<pt.size() && j>=0){
                long long val=pt[i]+t[j];
                if(val>mid)return false;
                i++;j-=4;
            }
            return true;
        };
        while(l<=r){
            long long mid=(l+r)>>1;
            if(check(mid))ans=mid,r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
};