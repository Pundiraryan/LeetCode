#define mod 1000000007
#define ll long long
class Solution {
public:
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
    ll modInverse(ll n, ll p)
{
return power(n, p - 2, p);
}
ll ncrmodp(ll n,ll r, ll p)
{
if (n < r)
return 0;
if (r == 0)
return 1;
ll fac[n + 1];
fac[0] = 1;
for (int i = 1; i <= n; i++)
fac[i] = (fac[i - 1] * i) % p;
return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p)% p;
}
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        if(k>26)return 0;
        int n=s.length();
        vector<int>fre(26);
        for(auto &x:s)fre[x-'a']++;
        sort(fre.begin(),fre.end());
        reverse(fre.begin(),fre.end());
        ll ans=1;
        int left=k,i=0;
        while(i<fre.size()){
            int j=i;
            while(j<fre.size() && fre[j]==fre[i]){
               j++;
            }
            int cnt=j-i;
            if(cnt<=left){
                ll curr=power(fre[i],cnt,mod)%mod;
                ans = (ans*curr)%mod;
                left-=cnt;
                if(!left)break;
            }else{
                ll combs=ncrmodp(cnt,left,mod)%mod;
                ll curr = power(fre[i],left,mod)%mod;
                ans = ans*((combs*curr)%mod)%mod;
                break;
            }
            i=j;
        }
        return ans;
    }
};