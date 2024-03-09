class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int n=nums1.length,m=nums2.length;
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]==nums2[j])return nums1[i];
            while(i<n && nums1[i]<nums2[j]){
                i++;
            }
            if(i==n)break;
            while(j<m && nums2[j]<nums1[i]){
                j++;
            }
        }
        return -1;
    }
}