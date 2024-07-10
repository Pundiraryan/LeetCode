class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(auto &x:logs){
            if(x[0]!='.' && x[0]!='/')ans++;
            if(x[0]=='.' && x[1]=='.'){
                if(ans>0)ans--;
            }
        }
        return ans;
    }
};