class Solution {
public:
    bool f(int i,int j,string &txt,string &query){
        int n=txt.size(),m=query.size();
        if(i==n && j==m)return true;
        if(i==n && isupper(query[j]))return false;
        if(j==m)return false;
        if(txt[i]==query[j]){
            return f(i+1,j+1,txt,query);
        }
        if(isupper(txt[i]) && isupper(query[j]))return false;
        if(islower(txt[i]) && isupper(query[j]))return false;
        return f(i,j+1,txt,query);
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int q=queries.size();
        vector<bool>ans(q);
        for(int i=0;i<q;i++){
            ans[i]=f(0,0,pattern,queries[i]);
        }
        return ans;
    }
};