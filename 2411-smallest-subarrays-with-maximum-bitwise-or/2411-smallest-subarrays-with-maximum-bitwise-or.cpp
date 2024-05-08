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
        seg[idx] = seg[2 * idx]|seg[2 * idx + 1];
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
        return lft|rght;
    }
};
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        vector<int>suffor(n);
        suffor[n-1]=nums[n-1];
        SGTree st(n);
        st.build(nums,0,n-1,1);
        for(int i=n-2;i>=0;i--)suffor[i]=(suffor[i+1]|nums[i]);
        for(int i=0;i<n;i++){
            int tar=suffor[i];
            int l=i,r=n-1;
            int res=r;
            while(l<=r){
                int mid=(l+r)>>1;
                int ov=st.maxi(1,0,n-1,i,mid);
                if(ov<tar){
                    l=mid+1;
                }else{
                    res=mid;
                    r=mid-1;
                }
            }
            ans[i]=res-i+1;
        }
        return ans;
    }
};