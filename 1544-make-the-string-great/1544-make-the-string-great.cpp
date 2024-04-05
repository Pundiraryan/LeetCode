class Solution {
public:
    string makeGood(string s) {
        string ans="";
        stack<char>st;
        for(auto &ch:s){
            if(st.empty())st.push(ch);
            else{
                if(abs(ch-st.top())==32){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};