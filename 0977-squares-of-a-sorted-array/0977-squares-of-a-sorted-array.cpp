class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        if(nums[0]>=0){
            for(int i=0;i<n;i++){
                ans[i]=nums[i]*nums[i];
            }
            return ans;
        }
        if(nums[n-1]<=0){
            for(int i=0;i<n;i++){
                ans[i]=nums[i]*nums[i];
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
        int pptr=0,nptr=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                pptr=i;
                break;
            }
        }
        nptr=pptr-1;
        // cout<<pptr<<endl;
        vector<int>res;
        while(res.size()<n){
            if(pptr>=n){
                while(nptr>=0){
                    res.push_back(nums[nptr]*nums[nptr]);
                    nptr--;
                }
                break;
            }
            else if(nptr<0){
                while(pptr<n){
                    res.push_back(nums[pptr]*nums[pptr]);
                    pptr++;
                }
                break;
            }
            else{
                int val1=nums[nptr]*nums[nptr];
                int val2=nums[pptr]*nums[pptr];
                if(val1<=val2){
                    res.push_back(val1);
                    nptr--;
                }else{
                    res.push_back(val2);
                    pptr++;
                }
            }
        }
        return res;
        
    }
};