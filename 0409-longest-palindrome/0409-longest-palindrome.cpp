class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>fre;
        for(auto &x:s)fre[x]++;
        int modd=0,es=0;
        bool has=false;
        for(auto &x:fre){
            if(x.second%2==1){
                has=true;
                es+=(x.second-1);
            }
            else es+=x.second;
        }
        if(has)es++;
        return es;
    }
};