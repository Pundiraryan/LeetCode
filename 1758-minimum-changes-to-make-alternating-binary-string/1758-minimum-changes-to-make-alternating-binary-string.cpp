class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        int ans=n;
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(i&1){
                if(s[i]=='1')cnt1++;
                else cnt2++;
            }else{
                if(s[i]=='0')cnt1++;
                else cnt2++;
            }
        }
        return min(cnt1,cnt2);
    }
};