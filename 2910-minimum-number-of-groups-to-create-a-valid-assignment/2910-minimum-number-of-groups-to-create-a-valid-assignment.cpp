class Solution {
public:
    unordered_map<int,int>fre;
    int check(vector<int>&nums,int i){
        int totgrps=0;
        for(auto &x:fre){
            int freq=x.second;
            int gipo=freq/(i+1);
            int re=freq%(i+1);
            if(re==0)totgrps+=gipo;
            else if(i-re<=gipo){
                totgrps+=(gipo+1);
            }else{
                return -1;
            }
        }
        return totgrps;
    }
    int minGroupsForValidAssignment(vector<int>& nums) {
        int n=nums.size();
        for(auto &x:nums)fre[x]++;
        int ans=INT_MAX;
        int grpsize=INT_MAX;
        for(auto &x:fre)grpsize=min(grpsize,x.second);
        for(int i=1;i<=grpsize;i++){
            int val=check(nums,i);
            if(val!=-1){
                ans=min(ans,val);
            }
        }
        return ans;
    }
};