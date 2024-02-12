class Solution {
    public int majorityElement(int[] nums) {
        int n=nums.length;
        int elem=nums[0],cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i]==elem)cnt++;
            else{
                --cnt;
                if(cnt==0){
                    elem=nums[i];
                    cnt=1;
                }
            }
        }
        return elem;
    }
}