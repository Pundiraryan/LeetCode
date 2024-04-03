#define mod 1000000007
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        long long zs=0,zos=0,zots=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zs=(zs+zs+1)%mod;
            }else if(nums[i]==1){
                zos=(zos+zos+zs)%mod;
            }else{
                zots=(zots+zots+zos)%mod;
            }
        }
        return zots%mod;
    }
};