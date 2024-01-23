class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<=8)return n;
        int ans=0;
        ans+=8;
        n-=8;
        int cv;
        if(n<=8)return ans+(n)*2;
        n-=8;
        if(n<=8)return ans+(8)*2+n*3;
        n-=8;
        return ans+8*5+4*n;
    }
};