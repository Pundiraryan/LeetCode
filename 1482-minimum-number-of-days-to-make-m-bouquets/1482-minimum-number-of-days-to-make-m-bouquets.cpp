class SGTree
{
    vector<int> seg;
 
public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(vector<int> &v, int low, int high, int idx)
    {
        if (low == high)
        {
            seg[idx] = v[low];
            return;
        }
        int mid = (low + high) / 2;
        build(v, low, mid, 2 * idx);
        build(v, mid + 1, high, 2 * idx + 1);
        seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
    }
    int maxi(int index, int l, int r, int start, int end)
    {
        if ((start > r) || (end < l))
        {
            return 0;
        }
        if ((start <= l) && (end >= r))
        {
            return seg[index];
        }
        int mid = (l + r) / 2;
        int lft = maxi((index * 2) , l, mid, start, end);
        int rght = maxi((index * 2) + 1, mid + 1, r, start, end);
        return max(lft, rght);
    }
};

class Solution {
public:
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long req=(long long)k*m;
        if(req>n)return -1;
        long long l=0,r=2e9;
        int ans=r;
        SGTree st(n);
        st.build(bloomDay,0,n-1,1);
        vector<pair<int,int>>vp;
        auto check=[&](long long mid)->bool{
            int bc=0,cc=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid)cc++;
                else cc=0;
                if(cc==k){
                    bc++;
                    cc=0;
                }
            }
            return bc>=m;
        };
        while(l<=r){
            long long mid=(l+r)>>1;
            if(check(mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};