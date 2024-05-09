class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans=0;
        auto check=[&](long long mid,int i)->bool{
            long long cv=0;
          for(int j=0; j<n; j++) {
                     if(mid*composition[i][j]-stock[j]>0) {
                         long long x=(mid*composition[i][j]-stock[j])*cost[j];
                         cv+=x;
                     }
                 }
            return cv<=budget;
        };
        for(int i=0;i<k;i++){
            long long l=0,r=1e9;
            int cans=0;
            while(l<=r){
                long long mid=(l+r)>>1;
                if(check(mid,i)){
                    cans=mid;
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            ans=max(ans,cans);
        }
        return ans;
    }
};