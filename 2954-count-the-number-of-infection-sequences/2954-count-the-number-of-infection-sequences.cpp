#define mod 1000000007
#define ll long long
ll fac[100005];
ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result
    x = x % p; // Update x if it is more than or equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
        res = (res * x) % p;
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}
ll ncr(ll n,ll r, ll p)
{
    if (n < r)
    return 0;
    if (r == 0)
    return 1;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p)% p;
}
class Solution {
public:
    void init(int n){
          fac[0] = 1;
        for (int i = 1; i <= n; i++)fac[i] = (fac[i - 1] * i) % mod;
    }
    int numberOfSequence(int n, vector<int>& sick) {
        init(n);
        long long res = 1;
    for (int i = 1; i < sick.size(); ++i) {
        int group = sick[i] - sick[i - 1] - 1;
        res = res * power(2, max(0, group - 1), mod) % mod; 
        res = res *ncr(sick[i] - i, group,mod) % mod;
    }
    return res * ncr(n - sick.size(), n - sick.back() - 1,mod) % mod;
    }
};