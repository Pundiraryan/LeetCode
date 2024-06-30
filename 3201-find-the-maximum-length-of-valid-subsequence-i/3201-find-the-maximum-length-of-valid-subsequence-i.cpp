class Solution {
public:
    int dp[200005][3];
    int f(int i,int pr,int pp,vector<int>&nums){
        int n=nums.size();
        if(i==n)return 0;
        if(dp[i][pp]!=-1)return dp[i][pp];
        int tk=-1e9,ntk=-1e9;
        if(pp==2){
            tk=1+f(i+1,pr,nums[i]%2,nums);
            ntk=f(i+1,pr,pp,nums);
        }else if(pp ==1){
            if(pr==1){
                if(nums[i]%2==0)tk=1+f(i+1,pr,0,nums);
                ntk=f(i+1,pr,pp,nums);
            }else{
                if(nums[i]%2==1)tk=1+f(i+1,pr,1,nums);
                ntk=f(i+1,pr,pp,nums);
            }
        }else{
            if(pr==1){
                if(nums[i]%2==1)tk=1+f(i+1,pr,1,nums);
                ntk=f(i+1,pr,pp,nums);
            }else{
                if(nums[i]%2==0)tk=1+f(i+1,pr,0,nums);
                ntk=f(i+1,pr,pp,nums);
            }
        }
        return dp[i][pp]= max(tk,ntk);
    }
    int maximumLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int v1=f(0,0,2,nums);
        memset(dp,-1,sizeof(dp));
        int v2=f(0,1,2,nums);
        return max(v1,v2);
    }
};