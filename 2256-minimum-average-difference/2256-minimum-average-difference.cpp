class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long>ps(n),ss(n);
        ps[0]=nums[0];
        ss[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+nums[i];
            ss[n-i-1]=ss[n-i]+nums[n-i-1];
        }
        // cout<<"hre\n";
        vector<long long>rans(n);
        rans[n-1]=ps[n-1]/n;
        for(int i=0;i<n-1;i++){
            long long v1=ss[i+1]/(n-1-i);
            long long v2=ps[i]/(i+1);
            rans[i]=abs(v1-v2);
        }
        long long val=*min_element(rans.begin(),rans.end());
        // cout<<val<<endl;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(rans[i]==val){
                ans=i;
                break;
            }
        }
        return ans;
    }
};