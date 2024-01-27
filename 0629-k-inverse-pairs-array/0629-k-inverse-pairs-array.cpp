#define mod 1000000007
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<int>curr(k+1,0);
        vector<int>prev(k+1,0);
        prev[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(j==0){
                    curr[j]=prev[j];
                    continue;
                }
                curr[j]=(prev[j]+curr[j-1])%mod;
                if(j>=i)curr[j]=(curr[j]-prev[j-i]+mod)%mod;
            }
            prev=curr;
        }
        return curr[k];
    }
};