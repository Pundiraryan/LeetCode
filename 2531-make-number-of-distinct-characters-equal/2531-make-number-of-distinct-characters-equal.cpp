class Solution {
public:
    bool check(vector<int>&v1,vector<int>&v2){
        int c1=0,c2=0;
        for(int i=0;i<26;i++){
            if(v1[i])c1++;
            if(v2[i])c2++;
        }
        return c1==c2;
    }
    bool isItPossible(string word1, string word2) {
        vector<int>freq1(26,0),freq2(26,0);
        for(auto &ch:word1)freq1[ch-'a']++;
        for(auto &ch:word2)freq2[ch-'a']++;
        for(int fc=0;fc<26;fc++){
            for(int sc=0;sc<26;sc++){
                if(freq1[fc]>0 && freq2[sc]>0){
                    freq1[fc]--;
                    freq1[sc]++;
                    freq2[fc]++;
                    freq2[sc]--;
                    if(check(freq1,freq2))return true;
                    freq1[fc]++;
                    freq1[sc]--;
                    freq2[fc]--;
                    freq2[sc]++;
                    
                }
            }
        }
        return false;
    }
};