class Solution {
public:
    int minOperations(int k) {
        int ans=1e9;
        int val=1;
        for(int i=0;i<=k;i++){
            int nv=val+i;
            int reqd=(k+nv-1)/nv;
            ans=min(ans,max(0,i+reqd-1));
        }
        return ans;
    }
};