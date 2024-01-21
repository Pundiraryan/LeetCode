class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int>fre(26,0);
        for(auto &x:word)fre[x-'a']++;
        sort(fre.rbegin(),fre.rend());
        int  ans=0;
        int cnt=0;
        for(auto &x:fre){
            ans+=(cnt/8 +1)*x;
            cnt++;
        }
        return ans;
    }
};