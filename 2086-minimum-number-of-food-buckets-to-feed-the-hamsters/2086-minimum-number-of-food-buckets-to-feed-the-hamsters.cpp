class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n=hamsters.length();
        if(n==1 && hamsters[0]=='H')return-1;
        if(n==1)return 0;
        if(hamsters[0]=='H' && hamsters[1]=='H')return -1;
        if(hamsters[n-1]=='H' && hamsters[n-2]=='H')return -1;
        for(int i=1;i<n-1;i++){
            if(hamsters[i-1]=='H' && hamsters[i]=='H' && hamsters[i+1]=='H')return -1;
        }
        string s=hamsters;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='.' || s[i]=='B')continue;
            if(i>0 && s[i-1]=='B'){
                continue;
            }
            else if(i<n-1 && s[i+1]=='.'){
                ans++;
                s[i+1]='B';
            }
            else if(i<n-1 && i>0 && s[i+1]=='H'){
                ans++;
                s[i-1]='B';
            }
            else if(i<n && i>0 && s[i-1]=='.'){
                ans++;
                s[i-1]=='B';
            }
        }
        return ans;
    }
};