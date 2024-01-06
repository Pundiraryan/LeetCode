class Solution {
public:
    int f(int i,vector<vector<int>>&vpi,vector<int>&dp){
        int n=vpi.size();
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        vector<int> temp; temp.push_back(vpi[i][1]); temp.push_back(-1);
        temp.push_back(-1);
        auto idx=lower_bound(vpi.begin(),vpi.end(),temp)-vpi.begin();
        int nottake=f(i+1,vpi,dp);
        int take=f(idx,vpi,dp)+vpi[i][2];
        return dp[i]=max(take,nottake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>vpi;
        for(int i=0;i<profit.size();i++){
            vpi.push_back({startTime[i],endTime[i],profit[i]});
        }
        vector<int>dp(profit.size()+1,-1);
        sort(vpi.begin(),vpi.end());
        return f(0,vpi,dp);
    }
};