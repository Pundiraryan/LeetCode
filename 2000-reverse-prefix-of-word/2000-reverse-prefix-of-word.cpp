class Solution {
public:
    string reversePrefix(string word, char ch) {
        int fo=-1;
        for(int i=0;i<word.length();i++){
            if(word[i]==ch){
                fo=i;break;
            }
        }
        reverse(word.begin(),word.begin()+fo+1);
        return word;
    }
};