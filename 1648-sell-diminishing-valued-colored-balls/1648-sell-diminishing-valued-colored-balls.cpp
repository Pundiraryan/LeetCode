#define mod 1000000007
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int n=inventory.size();
        sort(inventory.begin(),inventory.end());
        long long  l=0,r=inventory[n-1];
        long long sabequal=r;
        auto check=[&](long long mid)->bool{
            long long ov=orders;
          for(int i=n-1;i>=0;i--){
              long long sold=inventory[i]-mid;
              sold=max(sold,0ll);
              ov-=sold;
              if(ov<0)return false;
          }  
            return true;
        };
        while(l<=r){
            long long mid=(l+r)>>1;
            if(check(mid)){

                sabequal=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        // cout<<" -- "<<sabequal<<" -- "<<endl;
        int oo=orders;
        long long res=0;
        for(int i=0;i<n;i++)
        {
            int cv=inventory[i];
            int times=cv-sabequal;
            if(times<=0)continue;
            if(inventory[i]<=sabequal)continue;
            long long exccost=(sabequal*(long long)(sabequal+1))/2;
            long long inccost=((long long)cv*(long long)(cv+1))/2;
            long long val=(inccost-exccost);
            res=(res+val)%mod;
            oo-=times;
        }
        res =(res+(long long)(oo*sabequal))%mod;
        return res; 
        
    }
};