class Solution {
public:
    void solve(vector<int> &nums,vector<int> &curr,int &count,int ind,int k){
        if(ind==nums.size()){
            if(!curr.empty()){
                count++;
            }
            return;
        }
        bool flag=true;
        for(auto it:curr){
            if(abs(it-nums[ind])==k){
                flag=false;
                break;
            }
        }

        if(flag){
            curr.push_back(nums[ind]);
            solve(nums,curr,count,ind+1,k);
            curr.pop_back();
        }
        solve(nums,curr,count,ind+1,k);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int count=0;
        vector<int> curr;
        solve(nums,curr,count,0,k);
        return count;   
    }
};