class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int>v;
        vector<int>fre(26,0);
        for(auto &x:words){
            for(auto &ch:x)fre[ch-'a']++;
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            v.push_back(words[i].size());
        }
        int p=0,s=0;
        for(auto &x:fre){
            p+=(x/2);
            s+=(x%2);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            int cv=0;
            bool odd=v[i]%2;
            if(odd){
            if (s)s--;
            else{
                p--;
                s++;
            }
            v[i]--;
            }
            if(p>=v[i]/2){
                ans++;
                p-=v[i]/2;
            }
        }
        return ans;
    }
};