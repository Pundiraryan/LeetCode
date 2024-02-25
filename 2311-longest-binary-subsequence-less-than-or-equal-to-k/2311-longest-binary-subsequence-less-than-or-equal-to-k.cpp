class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.length();
        int ans=n;
        reverse(s.begin(),s.end());
        long long val=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1' && val+pow(2,i)>k){
                ans--;
            }
            else if(s[i]=='1' && val+pow(2,i)<=k){
                val+=pow(2,i);
            }
        }
        return ans;
    }
};