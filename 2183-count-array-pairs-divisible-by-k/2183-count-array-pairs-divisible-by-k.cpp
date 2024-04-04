#define ll long long
class Solution {
public:
    void calc(unordered_map<int,ll>&fre,int x){
        for(int i=1;i*i<=x;i++){
                if(x%i==0){
                    fre[i]++;
                    if(x/i !=i)fre[x/i]++;
                }
            }
    }
    long long countPairs(vector<int>& nums, int k) {
        ll ans=0;
        int n=nums.size();
        unordered_map<int,ll>fre;
        for(auto &x:nums){
            int mm=k/__gcd(x,k);
            ans+=(long long)fre[mm];
            calc(fre,x);
        }
        return ans;
    }
};