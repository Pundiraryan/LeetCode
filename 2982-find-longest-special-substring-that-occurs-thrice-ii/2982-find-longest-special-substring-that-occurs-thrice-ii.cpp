class Solution {
public:
    int maximumLength(string s) {
        int ans=-1;
        int n=s.length();
        unordered_map<char,vector<int>>fre;
        int i=0,j=0;
        char curr=s[0];
        while(j<n){
            int oj=j;
            while(oj<n && s[oj]==curr){
                oj++;
            }
            fre[curr].push_back(oj-j);
            curr=s[j];
            j=oj;
        }
        for(char ch='a';ch<='z';ch++){
            if(fre[ch].size()==0)continue;
            sort(fre[ch].begin(),fre[ch].end());
            int cs=fre[ch].size();
            ans=max(ans,fre[ch].back()-2);
            if(cs>=2){
                ans=max(ans,min(fre[ch][cs-2],fre[ch][cs-1]-1));
            }
            if(cs>=3){
                ans=max(ans,fre[ch][cs-3]);
            }
        }
        if(ans==0)return -1;
        return ans;
        
    }
};