#define INF 1e9
class Solution {
public:
    vector<pair<int,int>>t;
pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, min(r, tm)), 
                   get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
    int get_first(int v, int tl, int tr, int l, int r, int x) {
    if(tl > r || tr < l) return -1;
    if(t[v].first <= x) return -1;

    if (tl== tr) return tl;

    int tm = tl + (tr-tl)/2;
    int left = get_first(2*v, tl, tm, l, r, x);
    if(left != -1) return left;
    return get_first(2*v+1, tm+1, tr, l ,r, x);
}
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        vector<int>nge(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>=nums[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                nge[i]=st.top();
            }
            st.push(i);
        }
        t.resize(4*n+5);
        build(nums,1,0,n-1);
        for(int i=0;i<n;i++){
            int ngi=nge[i];
            if(ngi==n || ngi==n-1){
                ans[i]=-1;
                continue;
            }
               int idx=get_first(1,0,n-1,ngi+1,n,nums[i]);
            if(idx==-1){
                ans[i]=-1;
                continue;
            }
            ans[i]=nums[idx];
        }
        return ans;
    }
};