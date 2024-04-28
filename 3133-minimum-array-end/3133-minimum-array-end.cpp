class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=0;
        n--;
        vector<int>bx(63,-1),nx(63,-1);
        for(int i=0;i<31;i++){
            if((x>>i)&1)bx[i]=1;
            if((n>>i)&1)nx[i]=1;
        }
        int i=0,j=0;
        while(i<63){
            if(bx[i]==1){
                i++;
                continue;
            }
            bx[i]=nx[j];
            i++;
            j++;
        }
        for(int i=0;i<63;i++){
            if(bx[i]==1)ans+=(long long)(1ll<<i);
        }
        return ans;
        
    }
};