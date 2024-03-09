class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n=nums.size(),m=changeIndices.size();
        for(auto &x:changeIndices)x--;
        int l=0,r=m-1;
        int ans=-2;
        function<bool(int)>f=[&](int mid)->bool{
            unordered_map<int,int>li;
            for(int i=0;i<=mid;i++){
                li[changeIndices[i]]=i;
            }
            if(li.size()!=n)return false;
            int curr=0;
            for(int i=0;i<=mid;i++){
                if(i==li[changeIndices[i]]){
                    if(curr<nums[changeIndices[i]])return false;
                    curr-=nums[changeIndices[i]];
                }else{
                    curr++;
                }
            }
            return true;
        };
        while(l<=r){
            int mid=(l+r)>>1;
          if(f(mid))ans=mid,r=mid-1;
            else l=mid+1;
        }
        return ans+1;
    }
};