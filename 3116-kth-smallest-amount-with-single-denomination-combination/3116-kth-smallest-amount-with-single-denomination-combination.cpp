class Solution
{
   bool check(vector<int> &coins, long long x,long long k)
    {
        int n = coins.size();
        long long cnt = 0;
        for (int mask=1;mask<(1<<n);mask++)
        {
            long long lv=1;
            for (int bit=0;bit<n;bit++)
            {
                if (mask&(1<<bit))
                {
                    lv=lcm(lv,coins[bit]);
                }
            }
            if (__builtin_popcount(mask) & 1)cnt += x/lv;
            else cnt -= x/lv;
        }
        return cnt>=k;
    }

public:
    long long findKthSmallest(vector<int> &coins, int k)
    {
        long long l = *min_element(coins.begin(),coins.end()), r=1e12, ans = 0;
        while (l <= r)
        {
            long long mid=(r+l)/2;
            long long cnt=0;
            if(check(coins, mid,k)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};