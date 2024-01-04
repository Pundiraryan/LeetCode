class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>fre;
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            fre[nums[i]]++;
        }
        bool anse=true;
        for(auto &x:fre){
            if(x.second==1){
                anse=false;break;
            }
        }
        for(auto &x:fre){
            if(x.second%3==1 || x.second%3==2){
                ans+=(x.second/3)+1;
            }else{
                ans+=(x.second/3);               
            }
        }
        if(!anse)return -1;
        return ans;
    }
};