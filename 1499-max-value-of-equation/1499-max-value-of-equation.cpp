#define ll long long
class SGTree
{
    vector<ll> seg;
 
public:
    SGTree(ll n)
    {
        seg.resize(4 * n + 1);
    }
    void build(vector<ll> &v, ll low, ll high, ll idx)
    {
        if (low == high)
        {
            seg[idx] = v[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(v, low, mid, 2 * idx);
        build(v, mid + 1, high, 2 * idx + 1);
        seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
    }
    int maxi(int index, int l, int r, int start, int end)
    {
        if ((start > r) || (end < l))
        {
            return -1e9;
        }
        if ((start <= l) && (end >= r))
        {
            return seg[index];
        }
        int mid = (l +  r) / 2;
        int lft = maxi((index * 2) , l, mid, start, end);
        int rght = maxi((index * 2) + 1, mid + 1, r, start, end);
        return max(lft, rght);
    }
};
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n=points.size();
        long long ans=-1e9;
        vector<pair<int,int>>vp;
        vector<long long>arr(n);
        for(int i=0;i<n;i++){
            arr[i]=points[i][1]+points[i][0];
        }
        SGTree st(n);
        st.build(arr,0,n-1,1);
        for(auto &x:points)vp.push_back({x[0],x[1]});
        for(int i=0;i<n;i++){
            pair<int,int>sp={vp[i].first+k,-1e9};
            auto idx=lower_bound(vp.begin(),vp.end(),sp);
            if(idx==vp.end())--idx;
            else if(idx->first>vp[i].first+k)--idx;
            int iv=idx-vp.begin();
            cout<<i<<" "<<iv<<"-- "<<endl;
            long long cv=vp[i].second-vp[i].first;
            cout<<cv<<" "<<st.maxi(1,0,n-1,i+1,iv)<<endl;
                ans=max(ans,cv+st.maxi(1,0,n-1,i+1,iv));
        }
        return ans;
    }
};