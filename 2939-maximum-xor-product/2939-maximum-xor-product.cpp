#define mod 1000000007
#define ll long long
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        long long ans=1;
        for(int i=n-1;i>=0;i--){
            ll cv=(1ll<<i);
            ll abit=(cv&a);
            ll bbit=(cv&b);
            if(abit && bbit)continue;
            if(!abit && !bbit){
                a|=cv;
                b|=cv;
            }
            else{
                if(abit){
                    if(b<a){
                        a^=cv;
                        b^=cv;
                    }
                }else{
                    if(a<b){
                        a^=cv;
                        b^=cv;
                    }
                }
               
            }
        }
        ans=((long long )(a%mod)*(long long)(b%mod))%mod;
        return ans;
        
    }
};