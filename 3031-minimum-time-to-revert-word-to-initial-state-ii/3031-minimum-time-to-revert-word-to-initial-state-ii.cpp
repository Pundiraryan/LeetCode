typedef long long int ll;

const int M = 1e9+9;
const ll P = 31;

class Solution {
    
    vector<ll> prefix_hash;
    vector<ll> p_pow;
    void FillHash(const string & s) {
        int n = s.size();
        
        p_pow.resize(n+1), prefix_hash.resize(n+1);

        p_pow[0] = 1; 
        for (int i = 1; i <= n; i++) 
            p_pow[i] = (p_pow[i-1] * P) % M;

        prefix_hash[0] = 0;
        for (int i = 1; i <= n; i++) 
            prefix_hash[i] = (prefix_hash[i-1] +  p_pow[i]*(s[i-1] - 'a' + 1)) % M; 
    }  
    
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.length();
        FillHash(word);
        int ans = (n+k-1)/k;
        for (int j = n-1; j > 0; j --) {
            if (j % k != 0) continue;
            ll hash_front = (prefix_hash[n-j] * p_pow[j]) % M;
            ll hash_back  = (prefix_hash[n] - prefix_hash[j] + M) % M;
            if (hash_front == hash_back) ans = min (ans, j/k);
        }
        
        return ans;
    }
};