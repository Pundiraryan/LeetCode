bool cmp(vector<int>&a,vector<int>&b){
    if(a[1]<b[1])return true;
    else if(a[1]==b[1]){
        return a[0]<=b[0];
    }
    return false;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        int cptr=0,ans=1;
        sort(points.begin(),points.end(),cmp);
        for(int i=0;i<n;i++){
            if(points[i][0]>points[cptr][1]){
                ans++;
                cptr=i;
            }
        }
        return ans;
    }
};