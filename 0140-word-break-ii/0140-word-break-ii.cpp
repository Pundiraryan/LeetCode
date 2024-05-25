class Solution {
public:
    void f(int i,string &s,string &curr,unordered_set<string>&st,vector<string>&ans)    {
        int n=s.length();
        if(i>=n){
            ans.push_back(curr);
            return;
        }
        string ncurr=curr;
        for(int j=i;j<n;j++){
            string str=s.substr(i,j-i+1);
            if(st.find(str)==st.end())continue;
            curr+=str;
            if(j!=n-1)curr+=" ";
            f(j+1,s,curr,st,ans);
            curr=ncurr;
        }
    }
    vector<string> wordBreak(string s, vector<string>&wd) {
        unordered_set<string>st;
        for(auto &x:wd)st.insert(x);
        vector<string>ans;
        string curr="";
        f(0,s,curr,st,ans);
        return ans;
    }
};