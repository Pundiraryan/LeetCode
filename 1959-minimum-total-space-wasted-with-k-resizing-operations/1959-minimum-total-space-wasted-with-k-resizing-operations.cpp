class Solution {
public:
    int dp[205][205];
    int f(int i,int k,vector<int>&nums){
        int n=nums.size();
        if(i>=n)return 0;
        if(k<0)return 1e9;
        if(dp[i][k]!=-1)return dp[i][k];
        int ans=1e9,maxi=0,cst=0;
        for(int j=i;j<n;j++){
            maxi=max(maxi,nums[j]);
            cst+=nums[j];
            ans=min(ans,maxi*(j-i+1)-cst+f(j+1,k-1,nums));
        }
        return dp[i][k]=ans;
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,k,nums);
    }
};