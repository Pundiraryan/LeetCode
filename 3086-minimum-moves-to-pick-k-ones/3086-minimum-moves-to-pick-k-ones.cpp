
class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int mc) {
        int n = nums.size();
        int mco = 0;
        for (int i = 0; i < n; i ++) {
            int cnt = 0;
            for (int j = 0; j < 3 && i+j < n; j ++) {
                if (nums[j+i] == 1) cnt ++;
                else break;
            }
            mco = max (mco, cnt);
        }
                
        if (mco+mc >= k) {
            if (k <= mco) return (k-1);

            long long ans = (k-mco)*2;
            ans += (max(mco - 1,0));
            return ans;
        }
        long long ans=2*mc;
        vector<long long>op;
        op.push_back(-1);
        vector<long long>opps;
        opps.push_back(0);
        long long rans=1e18;
        for (int i = 0; i < n; i ++){
            if (nums[i] == 1) {
                op.push_back(i);
                opps.push_back(opps.back() + i);
            }
        }
            
        
        int reqc = k - mc;
        for (int l = 1, r = reqc; r < op.size(); l ++, r ++) {
            int pos = (l + r)/2;
             long long lft = (pos - l + 1)*op[pos] - (opps[pos] - opps[l-1]);
            long long rgt = (opps[r] - opps[pos]) - (r - pos)*op[pos];
            rans = min (rans, lft+rgt);
        }
        ans+=(long long)rans;
        return ans;
    }
};