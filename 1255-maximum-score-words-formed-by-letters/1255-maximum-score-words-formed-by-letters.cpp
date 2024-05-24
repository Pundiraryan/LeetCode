class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=words.size();
        vector<int>freq(26,0);
        for(auto &x:letters)freq[x-'a']++;
        int ans=0;
        auto f=[&](vector<int>&wl)->int{
          int sc=0;
            for(int i=0;i<26;i++){
                if(wl[i]>freq[i])return 0;
                sc+=(long long)wl[i]*score[i];
            }
            return sc;
        };
        for(int mask=0;mask<(1<<n);mask++){
            vector<int>wl(26,0);
            for(int i=0;i<n;i++){
                if((mask>>i)&1){
                    for(auto &x:words[i])wl[x-'a']++;
                    ans=max(ans,f(wl));
                }
            }
        }
        return ans;
    }
};