class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string>sp;
        sp.insert("+");sp.insert("-");sp.insert("/");sp.insert("*");
        unordered_map<string,function<int(int,int)>>mp={
        {"+",[](int a,int b){
            return a+b;
        }},{"-",[](int a,int b){
            return a-b;
        }},
        {"*",[](int a,int b){
            return a*b;
        }},
        {"/",[](int a,int b){
            return a/b;
        }},
};
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
            st.push(mp[x](a,b));
            }
        }
        return st.top();
    }
};