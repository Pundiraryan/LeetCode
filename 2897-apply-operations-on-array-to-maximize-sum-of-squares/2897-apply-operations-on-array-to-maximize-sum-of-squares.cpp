#define mod 1000000007
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>fre;
        vector<vector<int>>v(31,vector<int>(n));
        for(int i=0;i<=30;i++){
            vector<int>curr(n);
            for(int j=0;j<n;j++){
                curr[j]=((1<<i)&nums[j]);
                if(curr[j])fre[i]++;
            }
            sort(curr.begin(),curr.end());
            v[i]=curr;
        }
        long long res=0;
        int cidx=n-1;
        for(int i=0;i<k;i++){
            int val=0;
            for(int j=0;j<=30;j++){
                if(v[j][cidx])val|=(1<<j);
            }
            long long addval=1;
            addval*=val%mod;
            addval*=val%mod;
            res+=(addval)%mod;
            res%=mod;
            cidx--;
        }
        return res;
    }
};