class Solution {
public:
    int dp[2001];
int f(int i, vector<vector<bool>>& pal, int k, int n){
    if(i==n) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = 0;
    for(int j = i+k-1;j<n;j++){
        if(pal[i][j]){
            ans = max(ans, 1 + f(j+1, pal, k, n));
        }
    }
    ans = max(ans, f(i+1, pal, k, n));
    return dp[i] = ans;
}

int maxPalindromes(string s, int k) {
    int n = s.length();
    string curr;
    memset(dp,-1,sizeof(dp));
    vector<vector<bool>> pal(n, vector<bool>(n, 0));
    for(int i = 0;i<n;i++) pal[i][i] = 1;
    for(int i = 0;i<n-1;i++){
        if(s[i] == s[i+1]) pal[i][i+1] = 1;
    }
    for(int i = 3;i<=n;i++){
        for(int j = 0;j<n-(i-1);j++){
            if(s[j] == s[j + i-1] && pal[j+1][j+i-2]){
                pal[j][j+i-1] = 1;
            }
        }
    }
    return f(0, pal, k, n);
}
};