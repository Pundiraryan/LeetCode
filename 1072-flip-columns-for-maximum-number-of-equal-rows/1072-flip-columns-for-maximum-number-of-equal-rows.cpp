class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int ans=0;
        int r=matrix.size(),c=matrix[0].size();
        unordered_map<string,int>fre;
        for(int i=0;i<r;i++){
            string s1="",s2="";
            for(auto &x:matrix[i]){
                if (x==1){
                    s1.push_back('1');
                    s2.push_back('0');
                }else{
                    s1.push_back('0');
                    s2.push_back('1');
                }
            }
            fre[s1]++;fre[s2]++;
            ans=max({ans,fre[s1],fre[s2]});
        }
        return ans;
    }
};