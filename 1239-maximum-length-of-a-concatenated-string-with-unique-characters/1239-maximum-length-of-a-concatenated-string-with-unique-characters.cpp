class Solution {
public:
    // int dp[18][(1<<26)+5];
    int f(int i,int mask,vector<string>&arr){
        int n=arr.size();
        if(i==n)return 0;
        // if(dp[i][mask]!=-1)return dp[i][mask];
        int curr=0,valid=1;
        for(auto &x:arr[i]){
            int bp=x-'a';
            if(curr&(1<<bp) || mask&(1<<bp)){
                valid=0;break;
            }else{
                curr|=(1<<bp);
            }
        }
        if(!valid)return f(i+1,mask,arr);
        return max((int)arr[i].size()+f(i+1,mask|curr,arr),f(i+1,mask,arr));
    }
    int maxLength(vector<string>& arr) {
        // memset(dp,-1,sizeof(dp));
        return f(0,0,arr);
    }
};