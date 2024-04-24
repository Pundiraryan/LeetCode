class Solution {
public:
    int dp[25][25][2];
    int f(int i,int j,int c,vector<int>&nums){
        if(i>j)return 0;
        if(i==j){
            if(c)return nums[i];
            else return -nums[i];
        } 
        if(dp[i][j][c]!=-1)return dp[i][j][c];
        int ans=0;
        if(c){
            ans=max(nums[i]+f(i+1,j,c^1,nums),nums[j]+f(i,j-1,c^1,nums));
        }else{
            ans=min(-nums[i]+f(i+1,j,c^1,nums),-nums[j]+f(i,j-1,c^1,nums));
        }
        return ans;
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,nums.size()-1,1,nums)>=0;
    }
};