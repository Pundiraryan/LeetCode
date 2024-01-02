class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<unordered_set<int>>v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sz=v.size();
            int j=0;
            while(j<sz && v[j].find(nums[i])!=v[j].end())j++;
            if(j==sz){
                unordered_set<int>nst;
                nst.insert(nums[i]);
                v.push_back(nst);
            }else{
                v[j].insert(nums[i]);
            }
        }
        vector<vector<int>>res;
        for(auto &x:v){
            vector<int>curr;
            for(auto &y:x)curr.push_back(y);
            res.push_back(curr);
        }
        return res;
    }
};