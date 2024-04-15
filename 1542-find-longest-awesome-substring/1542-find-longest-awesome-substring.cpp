class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int,int>fre;
        int ans=0,n=s.length(),cv=0;
        for(int i=0;i<n;i++){
            cv^=(1<<(s[i]-'0'));
            if(fre.find(cv)!=fre.end()){
                ans=max(ans,i-fre[cv]);            
            }else{
                fre[cv]=i;
            }
            if(cv==0 || __builtin_popcount(cv)==1)ans=max(ans,i+1);
            for(int bit=0;bit<=10;bit++){
                int ncv=cv^(1<<bit);
                if(fre.find(ncv)!=fre.end()){
                ans=max(ans,i-fre[ncv]);            
            }
            }
        }
        return ans;
    }
};