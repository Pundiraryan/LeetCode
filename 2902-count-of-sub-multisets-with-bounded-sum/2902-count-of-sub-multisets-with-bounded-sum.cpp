#define MOD 1000000007
#define ll long long
class Solution {
public:
       int countSubMultisets(vector<int>& nums, int l, int r) {
        unordered_map<int, int> m;
        for (auto v: nums) {
            ++m[v];
        }
        vector<pair<int, int>> v;
        ll zeroesCount = m[0];
        m.erase(0);
        for (auto& p : m) {
            v.push_back(p);
        } 
        int n = size(v);
        vector<vector<int>> dp(n, vector<int>(r + 1, -1));
        function<ll(int, int)> f;
        f = [&](int i, int sum) -> ll {
            if (sum < 0) {
                return 0;
            }
            if (i == n) {
                return 1;
            }
            if (dp[i][sum] != -1) {
                return dp[i][sum];
            }
            auto[x, c] = v[i];
            return dp[i][sum] = (f(i + 1, sum) + f(i, sum - x) - f(i + 1, sum - (c + 1) * x) + MOD) % MOD;
        };
        return (f(0, r) - f(0, l - 1) + MOD) * (zeroesCount + 1) % MOD;
    }
};