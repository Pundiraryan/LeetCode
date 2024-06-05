class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        int n=words.size();
        for(char ch='a';ch<='z';ch++){
            int mf=105;
            for(int i=0;i<n;i++){
                int fc=0;
                for(auto &x:words[i])fc+=(x==ch);
                mf=min(mf,fc);
            }
            for(int i=0;i<mf;i++){
                string str="";
                str+=ch;
                ans.push_back(str);
            }
        }
        return ans;
    }
};