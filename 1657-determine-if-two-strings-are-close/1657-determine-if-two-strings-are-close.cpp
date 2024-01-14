class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int>fre1,fre2;
        vector<int>s1,s2;
        for(auto &x:word1)fre1[x]++;
        for(auto &x:word2){
            if(fre1[x]==0)return false;
            fre2[x]++;
        }
        for(auto &x:fre1)s1.push_back(x.second);
        for(auto &x:fre2)s2.push_back(x.second);
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1.size()!=s2.size())return false;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])return false;
        }
        return true;
    }
};