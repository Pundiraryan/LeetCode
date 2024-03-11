#define ll long long
class Solution {
public:
   ll minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 3;
        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<int>> pq1;
        ll sum=0,sum1=0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            pq.push(nums[i]);
            sum1 += nums[m-1-i];
            pq1.push(nums[m-1-i]);
        }
        vector<ll> dpl(n+2, 0);
        vector<ll> dpr(n+2, 0);
        dpl[0] = sum;
        dpr[n+1] = sum1;

        for (int i = 0; i < n; i++) {
            pq.push(nums[n+i]);
            sum -= pq.top();
            sum += nums[n+i];
            pq.pop();
            dpl[i+1] = sum;

            pq1.push(nums[m-n-i-1]);
            sum1 -= pq1.top();
            sum1 += nums[m-n-i-1];
            pq1.pop();
            dpr[n-i] = sum1;
        }
       ll ans = 1e18;
        for (int i = 0; i < n + 1; i++ ) {
            ans=min(ans, dpl[i]-dpr[i+1]);
        }
        return ans;
        
    }
};