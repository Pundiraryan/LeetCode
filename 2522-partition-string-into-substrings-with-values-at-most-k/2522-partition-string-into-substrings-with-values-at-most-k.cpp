class Solution {
public:
    int minimumPartition(string s, int k) {
        int n=s.length();
        long long val=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]-'0' >k)return -1;
            val=val*10 +(s[i] -'0');
            if(val>k){
                ans++;
                val=(s[i]-'0');
            }
        }
        return ans+1;
    }
};