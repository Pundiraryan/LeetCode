class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans=0;
        sort(ages.begin(),ages.end());
        for(int i=0;i<ages.size();i++){
            int yll=7+(ages[i]/2);
            int yul=ages[i];
            int res=upper_bound(ages.begin(),ages.end(),yul)-upper_bound(ages.begin(),ages.end(),yll)-1;
            ans+=max(0,res);
        }
        return ans;
    }
};