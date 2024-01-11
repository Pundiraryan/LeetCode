class Solution {
public:
    unordered_map<long long,int>dp;
    int f(int i,int uq,int c,int k,string &s){
        if(i>=s.length())return 0;
         long long key=((long long)i<<27)|(uq<<1)|c;
        if(dp.find(key)!=dp.end())return dp[key];
        int cidx=s[i]-'a';
        int nuq=uq|(1<<cidx);
        int uc=__builtin_popcount(nuq);
        int result=0;
        if(uc>k){
            result=1+f(i+1,1<<cidx,c,k,s);
        }else{
            result=f(i+1,nuq,c,k,s);
        }
        if(c){
            for(int ch=0;ch<26;ch++){
                int nnuq=uq|(1<<ch);
                int nuc=__builtin_popcount(nnuq);
                if(nuc>k){
                    result=max(result,1+f(i+1,1<<ch,0,k,s));
                }else{
                    result=max(result,f(i+1,nnuq,0,k,s));
                }
            }
        }
        return dp[key]=result;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        return 1+f(0,0,1,k,s);
    }
};