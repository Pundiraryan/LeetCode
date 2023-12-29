class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=3){
            int fn=nums[i],sn=nums[i+1],tn=nums[i+2];
            if(sn-fn<=k && tn-sn<=k && tn-fn<=k){
                ans.push_back({fn,sn,tn});
            }else{
                ans.clear();
                break;
            }
        }
        return ans;
    }
};