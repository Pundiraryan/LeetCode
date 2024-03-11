class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>ps(n,0);
        ps[0]=nums[0];
        int ans=1;
        for(int i=1;i<n;i++)ps[i]=(long long)(ps[i-1]+nums[i]);
        for(int i=0;i<n;i++){
            int l=1,r=i+1;
            while(l<=r){
                int mid=l+(r-l)/2;
                long long rs=(long long)nums[i]*mid;
                long long as=ps[i];
                if(i>=mid)as-=ps[i-mid];
                if(rs-as <=k){
                   ans=max(ans,mid);
                   l=mid+1; 
                }else{
                    r=mid-1;
                }
            }
        }
        return ans;
    }
};