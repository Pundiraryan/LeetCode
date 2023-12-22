class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        vector<int>ps(n),ss(n);
        if(s[0]=='0')ps[0]=1;
        else ps[0]=0;
        if(s[n-1]=='1')ss[n-1]=1;
        else ss[n-1]=0;
        for(int i=1;i<n;i++){
            ps[i]=ps[i-1];
            if(s[i]=='0')ps[i]++;
        }
        for(int i=n-2;i>=0;i--){
            if(s[i]=='1')ss[i]=1+ss[i+1];
            else ss[i]=ss[i+1];
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,ps[i]+ss[i+1]);
        }
        return ans;
    }
};