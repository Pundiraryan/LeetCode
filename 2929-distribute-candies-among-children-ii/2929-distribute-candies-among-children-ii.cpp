class Solution {
public:
    long long distributeCandies(int n, int limit) {
        if(3*limit<n)return 0;
        long long ans=0;
        for(int a=0;a<=min(n,limit);a++){
            int left=n-a;
            if(left>2*limit)continue;
            else if(left<limit)ans+=(left+1);
            else ans+=(2*limit-left+1);
        }
        return ans;
    }
};