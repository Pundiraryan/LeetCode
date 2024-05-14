class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int>dp(n,1);
        unordered_map<string,int>fre;
        unordered_map<string,int>fre1;
        dp[0]=1;
        fre[words[0]]=groups[0];
        fre1[words[0]]=0;
        vector<string>ans;
        for(int i=1;i<n;i++){
            int len=words[i].length();
            for(int j=0;j<len;j++){
                string tstr=words[i];
                for(char nc='a';nc<='z';nc++){
                    if(nc==words[i][j])continue;
                    tstr[j]=nc;
                    if(fre.find(tstr)!=fre.end() && groups[i]!=fre[tstr]){
                        dp[i]=max(dp[i],1+dp[fre1[tstr]]);
                    }
                }
            }
            fre[words[i]]=groups[i];
            fre1[words[i]]=i;
        }
       
        int mxv=*max_element(dp.begin(),dp.end());
        for(int i=n-1;i>=0;i--){
            if(dp[i]==mxv){
                    ans.push_back(words[i]);
                   break;
                }
            }
        string ps=ans.back();
        mxv--;
        while(true){
            int os=ans.size();
        for(int i=0;i<ans.back().size();i++){
            string nstr=ans.back();
            for(char nc='a';nc<='z';nc++){
                if(nc==words[fre1[ans.back()]][i])continue;
                nstr[i]=nc;
                if(fre.find(nstr)!=fre.end() && fre[ans.back()]!=fre[nstr] && dp[fre1[nstr]]==mxv){
                    ans.push_back(nstr);
                    mxv--;
                }
            }
        }
            if(ans.size()==os)break;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};