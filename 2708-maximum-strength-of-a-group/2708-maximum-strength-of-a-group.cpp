class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long ans=1;
        vector<int>nnums;
        if(nums.size()==1)return nums[0];
        sort(nums.rbegin(),nums.rend());
        int cnt=0;
        for(auto &x:nums){
            if(x>0){
                ans*=x;cnt++;
            }
            if(x<0)nnums.push_back(x);
        }
        if(cnt==0 && (nnums.size()==0||nnums.size()==1))return 0;
        if(nnums.size()>1){
            long long nval=1;
            int lim=0;
            if(nnums.size()%2==1)lim++;
            for(int i=nnums.size()-1;i>=lim;i--){
                nval*=nnums[i];
            }
            ans*=nval;
        
        }
        return ans;
    }
};