class Solution {
public:
    bool check(int mid,int n,vector<int>&arr){
        int curr=0;
        for(auto &x:arr)curr+=(x+mid-1)/mid;
        return curr<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int len=quantities.size();
        int l=1,r=*max_element(quantities.begin(),quantities.end());
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,n,quantities)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};