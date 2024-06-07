class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans="";
        vector<string>words;
        int n=sentence.length();
        int i=0;
        string curr="";
        while(i<n){
            if(sentence[i]!=' '){
                curr.push_back(sentence[i]);   
            }else{
                words.push_back(curr);
                curr="";
            }
            i++;
        }
        words.push_back(curr);
        unordered_map<string,int>fre;
        for(auto &x:dictionary)fre[x]++;
        for(int i=0;i<words.size();i++){
            string str="";
            bool f=false;
            for(auto &x:words[i]){
                str.push_back(x);
                if(fre.find(str)!=fre.end()){
                    ans+=str;
                    ans+=" ";
                    f=true;
                    break;
                }
            }
            if(!f){
                ans+=str;
                ans+=" ";
            }
        }
        while(ans.back()==' ')ans.pop_back();
        return ans;
        
    }
};