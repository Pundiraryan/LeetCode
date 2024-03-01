class Solution {
    int gcd(int a, int b) {

        while (b != 0) {
            int t = a;
            a = b;
            b = t % b;
        }
        return a;
    }
    public int countDifferentSubsequenceGCDs(int[] nums) {
       int n=nums.length;
        int[] gcdarr=new int[200001];
        for(int i=0;i<n;i++){
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    gcdarr[j]=gcd(gcdarr[j],nums[i]);
                    gcdarr[nums[i]/j]=gcd(gcdarr[nums[i]/j],nums[i]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<200001;i++){
            if(gcdarr[i]==i)ans++;
        }
    return ans;
    }
}