class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.length();
        int ans=-1;
        unordered_map<char,int>fre;
        for(int i=n-1;i>=0;i--){
            if(fre[s[i]]==0){
                fre[s[i]]=i;
            }
        }
        for(int i=0;i<n;i++){
            ans=max(ans,fre[s[i]]-i-1);
        }
        return ans;
    }
};