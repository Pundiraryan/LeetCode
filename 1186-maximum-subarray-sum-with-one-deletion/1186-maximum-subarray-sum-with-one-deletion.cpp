class Solution {
public:
    int maximumSum(vector<int>& arr) {
       int n=arr.size();
        int ans=-1e9,cs=0,ms=-1e9;
        for(auto &x:arr){
            cs+=x;
            ms=max(ms,cs);
            if(cs<0)cs=0;
        }
        ans=max(ans,ms);
        vector<int>dpl(n),dpr(n);
        dpl[0]=arr[0],dpr[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            dpl[i]=max({dpl[i-1]+arr[i],arr[i]});
        }
        for(int i=n-2;i>=0;i--){
            dpr[i]=max({dpr[i+1]+arr[i],arr[i]});
        }
        for(int i=1;i<n-1;i++){
            ans=max(ans,dpl[i-1]+dpr[i+1]);
        }
        return ans;
    }
};