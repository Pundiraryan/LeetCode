class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n=nums.size();
        map<int,vector<int>>fre;
        for(int i=0;i<n;i++)fre[nums[i]].push_back(i);
        int ans=n;
        for(auto &p:fre){
            int x=p.first;
            int cans=0;
            for(int i=0;i<fre[x].size()-1;i++){
                int diff=(fre[x][i+1]-fre[x][i])/2;
                cans=max(cans,diff);
            }
            cans=max(cans,(fre[x][0]+(n-1-fre[x][fre[x].size()-1]+1))/2);
            ans=min(ans,cans);
        }
        return ans;
    }
};