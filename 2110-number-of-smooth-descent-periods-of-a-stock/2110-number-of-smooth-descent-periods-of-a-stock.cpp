class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=0;
        int curr=prices[0];
        int cnt=1;
        for(int i=1;i<n;i++){
            if(curr-prices[i]==1){
                cnt++;
            }else{
                ans+=((long long)cnt*(long  long)(cnt+1))/2;
                cnt=1;
                
            }
            curr=prices[i];
        }
        ans+=((long long)cnt*(long long)(cnt+1))/2;
        return ans;
    }
};