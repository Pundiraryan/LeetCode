class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        stack<pair<char,int>>st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                if(s[i]=='(' || s[i]==')')st.push({s[i],i});
            }else{
                if(s[i]=='(')st.push({s[i],i});
                else if(s[i]==')' && st.top().first=='(')st.pop();
                else if(s[i]==')')st.push({s[i],i});
            }
        }
        unordered_set<int>avoid;
        while(!st.empty()){
            avoid.insert(st.top().second);
            st.pop();
        }
        if(avoid.empty())return s;
        for(int i=0;i<s.length();i++){
            if(avoid.find(i)!=avoid.end())continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};