class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans=0;
        unordered_map<int,int>fre;
        fre[0]++;
        int curr=0;
        for(auto &x:word){
            curr^=1<<(x-'a');
            ans+=fre[curr];
            for(int ch=0;ch<10;ch++){
                ans+=fre[curr^(1<<ch)];
            }
            fre[curr]++;
        }
        return ans;
    }
};