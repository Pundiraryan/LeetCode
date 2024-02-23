class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        if(s==t)return true;
        sort(s.rbegin(),s.rend());
        sort(t.rbegin(),t.rend());
        return !(s[0]=='0' || t[0]=='0');
    }
};