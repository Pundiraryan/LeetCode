#define ll long long
class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
        vector<ll>ans(n,0);
        vector<ll>pref(n+2,0);
        if(x>y)swap(x,y);
        if(x==y || y==x+1){
            for(int i=1;i<=n;i++){
                pref[1]++;
                pref[n-i+1]--;
            }
        }else{
             for(int i=y;i<=n;i++){
                pref[1]++;
                pref[n-i+1]--;
            }
            int m = y - (y-x)/2;
            for (int i = m; i < y; i ++){
                pref[1] ++, pref[n-i+1] --;
            }
            for (int i = x, to = m; i < m; i ++, to ++) {
                pref[1] ++, pref[to-i+1] --;
                int backpath=i-x+1;
                if (to+1 <= y) {
                    pref[backpath] ++, pref[(backpath-1) + (y-to+1)] --;
                }
                if (to+1 <= n) {
                    pref[backpath+1] ++, pref[backpath+n-y+1] --;
                }
            }

            for (int i = 1; i < x; i ++) {
                pref[1] ++, pref[m-i+1] --;
                int frontfix=x-i+1;
                if (m+1 <= y-1) {
                    pref[frontfix+1] ++, pref[frontfix+(y-m)] --;
                }
                pref[frontfix] ++, pref[frontfix+ (n-y+1)] --;
            }
        }
       
        for(int i=1;i<=n;i++)pref[i]+=pref[i-1];
        for(int i=1;i<=n;i++)ans[i-1]=pref[i]*2;
        return ans;
    }
};