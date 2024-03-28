bool cmp(vector<int>&a,vector<int>&b){
    return (a[1]-a[0]>b[1]-b[0]);
}
class Solution {
public:
    bool check(vector<vector<int>>&vp,int mid){
        int ce=mid;
        for(auto &x:vp){
            if(ce<x[1])return false;
            ce-=x[0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),cmp);
        int r=0;
        for(auto &x:tasks){
            r+=x[1];
        }
        int l=1;
        int ans=r;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(tasks,mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};