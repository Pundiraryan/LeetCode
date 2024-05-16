class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n=words.size();
        int ans=0;
        map<pair<vector<int>,vector<int>>,int>fre;
        for(int i=0;i<n;i++){
            vector<int>ep(26,0),op(26,0);
            for(int j=0;j<words[i].length();j++){
                if(j&1){
                    op[words[i][j]-'a']++;
                }else{
                    ep[words[i][j]-'a']++;
                }
            }
            fre[{ep,op}]++;
        }
        return fre.size();
    }
};