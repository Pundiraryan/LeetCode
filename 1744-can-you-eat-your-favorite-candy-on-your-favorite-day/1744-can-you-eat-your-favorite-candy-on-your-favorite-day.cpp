class Solution {
public:
    vector<bool> canEat(vector<int>&nums, vector<vector<int>>&q) {
        int n=nums.size();
        vector<bool>ans(q.size(),false);
        vector<long long>ps(n);
        ps[0]=nums[0];
        for(int i=1;i<n;i++)ps[i]=(ps[i-1]+nums[i]);
        int idx=0;
        for(auto &x:q){
            int tp=x[0],day=x[1],lim=x[2];
            long long tar=(tp==0)?0:ps[tp-1];
            long long mtar=ps[tp];
            long long meat=(long long)(day+1)*lim;
            if(day+1<=mtar && meat>tar){
                ans[idx]=true;
            }
            idx++;
        }
        return ans;
    }
};