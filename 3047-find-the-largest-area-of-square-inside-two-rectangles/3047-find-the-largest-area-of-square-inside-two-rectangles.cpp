#define ll long long
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        ll n=tr.size();
        ll ans=0;
        for(ll i=0;i<n;i++){
            for(ll j=i;j<n;j++){
                if(j==i)continue;
                if(bl[i][0]>tr[j][0]||bl[i][1]>tr[j][1]||tr[i][0]<bl[j][0]||tr[i][1]<bl[j][1]) continue;
                    int x1=max(bl[i][0],bl[j][0]);
                    int y1=max(bl[i][1],bl[j][1]);
                    int x2=min(tr[i][0],tr[j][0]);
                    int y2=min(tr[i][1],tr[j][1]);
                    int side=min(y2-y1,x2-x1);
                    long long av=(ll)side*(ll)side;
                    ans=max(ans,av);
            }
        }
        return ans;
    }
};