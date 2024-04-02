class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
      int ans=0;
        int n=s.length();
        vector<int>v(n);
        for(int i=0;i<n;i++)v[i]=(abs(s[i]-t[i]));
        int cs=0,i=0,j=0;
        while(j<n){
            cs+=v[j];
            while(cs>maxCost){
                cs-=v[i];
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};