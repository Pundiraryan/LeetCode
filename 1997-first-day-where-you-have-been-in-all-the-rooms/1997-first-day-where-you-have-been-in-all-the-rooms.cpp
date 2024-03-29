#define mod 1000000007
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
         int n=nextVisit.size();
        vector<long long>pehladin(n,0);
        int currentdin=0;
        for(int i=0;i<n;i++){
            if(i==n-1)return currentdin;
            if(nextVisit[i]==i){
                currentdin+=2;
            }else{
                int peecheselauto=(currentdin-pehladin[nextVisit[i]]+mod)%mod;
                currentdin+=(peecheselauto+2+mod)%mod;
            }
            currentdin%=mod;
            pehladin[i+1]=currentdin;
        }
        return -1;
    }
};