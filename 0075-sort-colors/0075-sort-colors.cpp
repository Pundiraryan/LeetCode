class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int ptr1=0,ptr2=0,ptr3=n-1;
        while(ptr2<=ptr3){
            if(nums[ptr2]==0){
                swap(nums[ptr1],nums[ptr2]);
                ptr1++;ptr2++;
            }else if(nums[ptr2]==1){
                ptr2++;
            }else{
                swap(nums[ptr2],nums[ptr3]);
                ptr3--;
            }
        }
    }
};