class Solution {
public:
    bool isp(string &s){
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]!=s[n-1-i])return false;
        }
        return true;
    }
    void f(int i,vector<string>&curr,vector<vector<string>>&ans,string &s){
        int n=s.length();
        if(i>=n){
            ans.push_back(curr);
            return;
        }
        string str="";
        for(int j=i;j<n;j++){
            str+=s[j];
            if(isp(str)){
                curr.push_back(str);
                f(j+1,curr,ans,s);
                curr.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
       vector<vector<string>>res;
        vector<string>curr;
        f(0,curr,res,s);
        return res;
    }
};