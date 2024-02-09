class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        List<Integer>ans=new ArrayList<>();
        Arrays.sort(nums);
        int n=nums.length;
        int[] dp=new int[n+1];
        for(int i=0;i<=n;i++)dp[i]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j])==0){
                    dp[i]=Math.max(dp[i],1+dp[j]);
                }
            }
        }
        int maxlen=-1,maxi=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>maxlen){
                maxlen=dp[i];
                maxi=i;
            }
        }
        ans.add(nums[maxi]);
        int clen=maxlen-1;
        for(int i=maxi-1;i>=0 && clen>0;i--){
            int sz=ans.size()-1;
            if(ans.get(sz)%nums[i]==0 && dp[i]==clen){
                ans.add(nums[i]);
                clen--;
            }
        }
         Collections.reverse(ans);
        return ans;
    }
}