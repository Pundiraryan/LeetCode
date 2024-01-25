class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.length();
        vector<int>freqe(26,0);
        vector<int>freqo(26,0);
        for(int i=0;i<n;i++){
            if(i&1){
                freqo[s1[i]-'a']++;
                freqo[s2[i]-'a']--;
            }else{
                freqe[s1[i]-'a']++;
                freqe[s2[i]-'a']--;
            }
        }
        if(*max_element(freqe.begin(),freqe.end())==0 && *max_element(freqo.begin(),freqo.end())==0)return true;
        return false;
    }
};