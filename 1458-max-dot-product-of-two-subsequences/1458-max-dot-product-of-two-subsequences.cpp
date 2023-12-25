class Solution {
public:
    int dp[505][505][2];
    int f(int i,int j,int taken,vector<int>&nums1,vector<int>&nums2){
        int n=nums1.size(),m=nums2.size();
        if((i==n || j==m) && taken)return 0;
        if((i==n || j==m) && !taken)return -12345678;
        if(dp[i][j][taken]!=-1)return dp[i][j][taken];
        int ans=INT_MIN;
        int case1=nums1[i]*nums2[j]+max(0,f(i+1,j+1,1,nums1,nums2));
        int case2=f(i+1,j,0,nums1,nums2);
        int case3=f(i,j+1,0,nums1,nums2);
        int case4=f(i+1,j+1,0,nums1,nums2);
        ans=max({ans,case1,case2,case3,case4});
        return dp[i][j][taken]=ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2){
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,nums1,nums2);
    }
};