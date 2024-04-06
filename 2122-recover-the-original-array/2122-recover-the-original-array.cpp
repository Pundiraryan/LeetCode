class Solution {
public:
    vector<int> check(vector<int>&nums,int td){
        vector<int>res;
        unordered_map<int,int>fre;
        for(auto &x:nums)fre[x]++;
        for(auto &x:nums){
            if(fre.find(x)==fre.end() || fre.find(x+td)==fre.end())continue;
            fre[x]--;
            if(fre[x]==0)fre.erase(x);
            fre[x+td]--;
            if(fre[x+td]==0)fre.erase(x+td);
            res.push_back(x+(td/2));
        }
        return res;
    }
    vector<int> recoverArray(vector<int>& nums) {
        unordered_map<int,int>fre;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_set<int>tk;
        for(int i=0;i<n;i++){
            int val=nums[i]-nums[0];
            if(val>0 && val%2==0){
                tk.insert(val);
            }
        }
        vector<int>ans;
        for(auto &x:tk){
            vector<int>res=check(nums,x);
            if(res.size()==n/2)return res;
        }
            return ans;
    }
};