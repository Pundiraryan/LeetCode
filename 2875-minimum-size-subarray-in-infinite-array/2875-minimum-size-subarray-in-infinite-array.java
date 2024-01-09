class Solution {
    public int minSizeSubarray(int[] nums, int target) {
        int n=nums.length;
        int[] nnums=new int[2*n];
        int sum=0;
        for(int i=0;i<n;i++){
            nnums[i]=nums[i];
            nnums[i+n]=nums[i];
            sum+=nums[i];
        }
        if(target%sum==0){
            return n*(target/sum);
        }
        int obv=target/sum;
        int nt=target%sum;
        target=nt;
        int ans=Integer.MAX_VALUE;
        int i=0,j=0;
        int currsum=0;
        while(j<2*n){
            currsum+=nnums[j];
            if(currsum==target){
                ans=Math.min(ans,j-i+1);
            }
            else if(currsum>target){
                while(i<=j && currsum>target){
                    currsum-=nnums[i];
                    i++;
                }
                if(currsum==target){
                    ans=Math.min(ans,j-i+1);
                }
            }
            j++;
        }
        if(ans==Integer.MAX_VALUE)return -1;
        return ans+obv*n;
    }
}