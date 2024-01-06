class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n=s.length();
        int ans=1;
        int i=0;
        set<int>st;
        for(int j=1;j<n;j++){
            if(s[j]==s[j-1])st.insert(j);
            if(st.size()==2){
                i=*st.begin();
                st.erase(st.begin());
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};