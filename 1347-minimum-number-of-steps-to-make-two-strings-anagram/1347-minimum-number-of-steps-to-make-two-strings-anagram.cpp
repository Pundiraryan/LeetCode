class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.length();
        unordered_map<char,int>fre;
        for(int i=0;i<n;i++){
            fre[t[i]]++;
            fre[s[i]]--;
        }
        int ans=0;
        for(auto &x:fre){
            ans+=max(0,x.second);
        }
        return ans;
    }
};