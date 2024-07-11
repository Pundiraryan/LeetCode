class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        vector<pair<int,int>>vp;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                vp.push_back({st.top(),i});
                st.pop();
            }
        }
        for(auto &x:vp){
            reverse(s.begin()+x.first,s.begin()+x.second);
        }
        string res="";
        for(auto &x:s){
            if(x!='(' && x!=')')res.push_back(x);
        }
        return res;
    }
};