#define ll long long
class Solution {
public:
    bool isvowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    long long beautifulSubstrings(string s, int k) {
        ll ans=0;
        map<int,map<int,int>>fre;
        fre[0][0]=1;
        int vc=0,cc=0;
        for(auto &x:s){
            if(isvowel(x))vc++;
            else cc++;
            for(auto &freq:fre[vc-cc]){
                    if((vc-freq.first)*(vc-freq.first)%k==0){
                        ans+=freq.second;
                    }
                }
            fre[vc-cc][vc%k]++;
            }
              return ans;
        }
  
};