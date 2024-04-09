class Solution {
public:
    long long f(int i,int j,int k,vector<int>&nums){
        int n=nums.size();
        if(i>=n || j>=n || i<0 || j-i+1<k)return 0;
        long long sum=0;
        for(int l=i;l<i+k;l++)sum+=nums[l];
        long long ans=sum;
        for(int l=i+k;l<=j;l++){
            sum=sum-nums[l-k]+nums[l];
            ans=max(ans,sum);
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        long long res=0;
        long long cs=0;
        for(int i=0;i<firstLen;i++)cs+=nums[i];
        long long ov=f(firstLen,n-1,secondLen,nums);
        cout<<cs<<" -- "<<ov<<endl;
        res=cs+ov;
        for(int j=firstLen;j<n;j++){
            cs=cs+nums[j]-nums[j-firstLen];
            res=max(res,cs+max(f(0,j-firstLen,secondLen,nums),f(j+1,n-1,secondLen,nums)));
        }
        return res;
    }
};