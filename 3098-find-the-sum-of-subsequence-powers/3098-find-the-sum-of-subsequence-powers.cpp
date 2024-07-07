#define mod 1000000007
class Solution {
public:
    int dp[55][55][55][55];
    int f(int i,int pi,int x,int y,int len,int k,vector<int>&nums){
        int n=nums.size();
        if(i==n){
            if(len==k)return nums[y]-nums[x];
            return 0;
        }
        if(dp[pi+1][x][y][len]!=-1)return dp[pi+1][x][y][len];
        int sum=0;
        if(pi==-1){
            sum=(sum+f(i+1,pi,x,y,len,k,nums))%mod;
            sum=(sum+f(i+1,i,x,y,len+1,k,nums))%mod;
        }else{
            sum=(sum+f(i+1,pi,x,y,len,k,nums))%mod;
            int cv=nums[i]-nums[pi];
            if(cv<nums[y]-nums[x]){
                sum=(sum+f(i+1,i,pi,i,len+1,k,nums))%mod;
            }else{
                sum=(sum+f(i+1,i,x,y,len+1,k,nums))%mod;
            }
        }
        return dp[pi+1][x][y][len]=sum;
    }
    int sumOfPowers(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        return f(0,-1,0,nums.size()-1,0,k,nums);
    }
};