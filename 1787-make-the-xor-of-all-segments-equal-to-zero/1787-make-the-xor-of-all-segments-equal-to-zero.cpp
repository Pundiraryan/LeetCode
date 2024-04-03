class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>freq(k,vector<int>(1024,0));
        vector<vector<int>>dp(k,vector<int>(1024,n+1));
        unordered_set<int>st[k];
        for(int i=0;i<n;i++){
            int pos=i%k;
            freq[pos][nums[i]]++;
            st[pos].insert(nums[i]);
        }
        int prebest=0;
        for(int i=0;i<k;i++){
            // n%k==i kitne hai
            int cnt=n/k+(((n%k)>i)?1:0);
            int changes=n+1;
                        //i tak ka xor hai j
            //konsi xor value ke liye changes minimum hai
            for(int j=0;j<1024;j++){
                if(i==0){
                    //saari positions me se n%k==i valo me j kitni baar hai
                    dp[i][j]=cnt-freq[i][j];
                }else{
                    //ith element kya rakhe -
                // already me se kuch
                for(auto &x:st[i]){
                    dp[i][j]=min(dp[i][j],dp[i-1][j^x]+cnt-freq[i][x]);
                }
                //kuch alag hi rakhde -previous best
                dp[i][j]=min(dp[i][j],prebest+cnt);
                        
                }
                 changes=min(changes,dp[i][j]);
                
            }
            prebest=changes;
           
        }
        return dp[k-1][0];
    }
};