class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 1));
        int ans = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                int temp = (nums[j] + nums[i])%k;
                dp[i][temp] = max(1 + dp[j][temp],dp[i][temp]);
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                ans = max(ans, dp[i][j]);
        return ans;
    }
};