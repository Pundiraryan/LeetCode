
long long logb2(long long x){ return __builtin_clzll ((long long)1) - __builtin_clzll(x); }
class Solution {
public:
    long long find(long long pos,long long n){
        long long retval=0;
        long long maxi=1LL<<pos;
        retval+=(n/maxi)*(maxi>>1);
        if(n%maxi >=(maxi/2)){
            retval+=(n%maxi - maxi/2)+1;
        }
        return retval; 
    }
    long long findMaximumNumber(long long k, int x) {
        long long ans=1;
        long long low=1,high=1e15;
        while(low<=high){
            long long mid=(low+high)>>1;
            long long bc=logb2(mid)+1;
            long long lim=bc/x;
            long long all=0;
            for(long long i=1;i<=lim;i++){
                all+=find(x*i,mid);
            }
            if(all<=k){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    return ans;
    }
};