class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<int,vector<int>>fre,fre1;
        for(int i=0;i<s.length();i++){
            fre[s[i]-'a'].push_back(i);
            fre1[t[i]-'a'].push_back(i);
        }
        set<vector<int>>st;
        for(auto &x:fre)st.insert(x.second);
        for(auto &x:fre1){
            if(st.find(x.second)==st.end())return false;
        }
        return true;
    }
};