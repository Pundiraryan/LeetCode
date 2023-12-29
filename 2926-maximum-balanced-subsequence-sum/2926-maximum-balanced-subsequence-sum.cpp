#define ll long long 
struct SegmentTree
{
	vector<ll> t;
	SegmentTree(int n){
		t.resize(4*n);
	}
	void update(int index,int l,int r,int pos,ll val){
		if(pos < l || pos > r)return;
		if(l == r){
			t[index] = val;
			return;
		 }
		int mid = (l+r)>>1;
		update(index<<1,l,mid,pos,val);
		update(index<<1|1,mid+1,r,pos,val);
		t[index] = max(t[index<<1],t[index<<1|1]);
   }
    ll query(int index,int l,int r,int lq,int rq){
		if(l > rq || lq > r)return 0;
		if(lq <= l && r <= rq){
			return t[index];
		}
		int mid = (l+r)>>1;
		ll left = query(index<<1,l,mid,lq,rq);
		ll right = query(index<<1|1,mid+1,r,lq,rq);
		return max(left,right);
   }
};
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        ll n=nums.size();
        vector<pair<ll,ll>>v;
        for(ll i=0;i<n;i++){
            v.push_back({nums[i]-i,i});
        }
        sort(v.begin(),v.end());
        
        // dp pe range query for valid indeces
        // valid indices ko nums ke indices me map karna hai 
        unordered_map<int,int>fre;
        for(int i=0;i<n;i++){
            fre[v[i].second]=i;
        }
        //ab hum nums pe iterate karenge
        ll ans=-INT_MAX;
        SegmentTree st(n);
        vector<ll>dp(n,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=max((ll)nums[i],(ll)nums[i]+st.query(1,0,n-1,fre[i],n-1));
            st.update(1,0,n-1,fre[i],dp[i]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};