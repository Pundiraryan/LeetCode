class Solution {
public:
    int dp[101][101];
    int f(int i, int j, int m, vector<int>&nums,vector<int>&ps) {
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        int sum = 0;
        if (i == 0) sum = ps[j];
        else sum = ps[j] - ps[i - 1];

        if (j - i == 1 && sum >= m) return dp[i][j] = 1;
        if (sum < m) return dp[i][j] = false;

        int ans=0;
        for (int k = i; k < j; k++) {
            if (f(i, k, m,nums, ps) == 1 && f(k + 1, j,m, nums, ps) == 1) {
                 ans=1;
                break;
            }
        }
        return dp[i][j]=ans;
    }

    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(n==2)return true;
        memset(dp, -1, sizeof(dp));
        vector<int>ps(n,0);
        ps[0] = nums[0];
        for (int i = 1; i < n; i++) {
            ps[i] = ps[i - 1] + nums[i];
        }
        return f(0, n - 1,m,nums,ps);
    }
};