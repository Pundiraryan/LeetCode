class Solution {
public:
     vector<int> z_function(string s) {
//z[i] - ith index se started substring ka kitna prefix string ke prefix se match karta (z[0]=0)
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
    long long sumScores(string s) {
        long long ans=0;
        int n=s.length();
        vector<int>v=z_function(s);
        for(auto &x:v)ans+=x;
        ans+=n;
        return ans;
    }
};