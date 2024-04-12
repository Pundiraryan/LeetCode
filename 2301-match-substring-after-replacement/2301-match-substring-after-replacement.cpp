class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        map<char,set<char>>fre;
        for(auto &x:mappings){
            fre[x[0]].insert(x[1]);
        }
        int n=s.length(),k=sub.length();
        for(int i=0;i<n;i++){
            bool anse=true;
            for(int j=0;j<k;j++){
                if(s[i+j]!=sub[j] && fre[sub[j]].find(s[i+j])==fre[sub[j]].end()){
                    anse=false;
                    break;
                }
            }
            if(anse)return true;
        }
        return false;
    }
};