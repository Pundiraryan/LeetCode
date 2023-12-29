class Solution {
public:
    string ms(string &s1,string &s2){
        if(s1.length()<s2.length())return s1;
        if(s1.length()>s2.length())return s2;
        int i=0;
        int n=s1.length();
        while(i<n && s1[i]==s2[i])i++;
        if(i==n)return s1;
        else if(s1[i]<s2[i])return s1;
        return s2;
   }
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        string ans(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string curr=s.substr(i,j-i+1);
                int cnt=0;
                for(auto &x:curr){
                    if(x=='1')cnt++;
                }
                if(cnt!=k)continue;
                ans=ms(ans,curr);
            }
        }
        int cnt=0;
        for(auto &x:ans)cnt+=(x=='1');
        if(cnt==n+1 || cnt!=k)return "";
        return ans;
    }
};