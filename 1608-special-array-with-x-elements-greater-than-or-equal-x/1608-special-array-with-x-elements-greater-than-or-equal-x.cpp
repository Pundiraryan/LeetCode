class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int x=0;x<=n;x++){
            int val=nums.end()-lower_bound(nums.begin(),nums.end(),x);
            if(val==x)return x;
        }
        return -1;
    }
};