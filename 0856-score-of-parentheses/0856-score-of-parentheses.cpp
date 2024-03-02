class Solution {
public:
    int scoreOfParentheses(string s) {
        int st=0,ans=0;
        char prev='(';
        for(auto &ch:s){
            if(ch=='(')st++;
            else{
                st--;
                if(prev=='('){
                    ans+=pow(2,st);
                }
            }
            prev=ch;
        }
        return ans;
    }
};