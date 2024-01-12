class Solution {
public:
    unordered_set<char>vowels={'a','A','e','E','i','I','o','O','u','U'};
    bool halvesAreAlike(string s) {
        int n=s.length();
        int ct1=0,ct2=0;
        for(int i=0;i<n;i++){
            if(i<n/2)ct1+=(vowels.find(s[i])!=vowels.end());
            else{
                ct2+=(vowels.find(s[i])!=vowels.end());
            }
        }
        return ct1==ct2;
    }
};