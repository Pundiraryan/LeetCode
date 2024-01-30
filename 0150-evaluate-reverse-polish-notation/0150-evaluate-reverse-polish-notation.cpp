class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string>sp;
        sp.insert("+");sp.insert("-");sp.insert("/");sp.insert("*");
        stack<int>st;
        for(auto &x:tokens){
            if(sp.find(x)==sp.end()){
                int num=stoi(x);
                st.push(num);
            }else{
                  int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (x == "+")
                st.push(a + b);
            else if (x == "-")
                st.push(a - b);
            else if (x == "*")
                st.push(a * b);
            else
                st.push(a / b);
            }
        }
        return st.top();
    }
};