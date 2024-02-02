class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int id, int vd) {
        vector<int>ans(2);
        ans[0]=-1;
        ans[1]=-1;
        int n=nums.size();
        vector<int>suffmin(n,1e9+5);
        suffmin[n-1]=nums[n-1];
        int curr=nums[n-1];
        unordered_map<int,int>fre;
        for(int i=0;i<n;i++){
            fre[nums[i]]=i;
        }
        for(int i=n-2;i>=0;i--){
            suffmin[i]=min(suffmin[i+1],nums[i]);
        }
        vector<int>suffmax(n,-1);
        suffmax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffmax[i]=max(suffmax[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            int nidx=i+id;
            if(nidx<n){
                int val1=suffmin[nidx];
                int val2=suffmax[nidx];
                if(abs(nums[i]-val1)>=vd){
                    ans[0]=i;ans[1]=fre[val1];
                    break;
                }else if(abs(nums[i]-val2)>=vd){
                    ans[0]=i;ans[1]=fre[val2];
                    break;
                }
            }
        }
        return ans;
    }
};