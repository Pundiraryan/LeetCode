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
    string longestPrefix(string s) {
        vector<int>v=z_function(s);
        int midx=-1,mv=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==v.size()-i && v[i]>mv){
                midx=i;
                mv=v[i];
            }
        }
        if(midx==-1)return "";
        return s.substr(midx,mv);
    }
};