#define ll long long
#define vl vector<long long>
#define mod 100000007
vl preh,preb;
ll mm(ll a, ll b){
        return (a*b)%mod;
    }
ll p=53;
//pre-processing 
    void init(vector<int> &nums){
        int n = nums.size();
        preh.resize(n+1,0);
        preb.resize(n+1,1);
        for(int i=1; i<=n; i++){
            preh[i] = (preh[i-1] + mm(nums[i-1], preb[i-1])) % mod;
            preb[i] = mm(preb[i-1], p);
        }
    }

    //fucntion to check if the hash value of two subarrays is equal
    bool isEqual(int start1, int start2, int len){
        return mm(preb[start2], (preh[start1 + len] - preh[start1] + mod) % mod) == mm(preb[start1], (preh[start2 + len] - preh[start2] + mod) % mod);
    }
class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n=nums.size();
        init(nums);
        int ans=0;
        for(int j=0;j<n-2;j++){
            for(int k=j+1;k<n-1;k++){
                int len1 = j+1, len2 = k-j, len3 = n - k- 1;
                bool fc= (j+1)<=(k-j) && isEqual(0,j+1,j+1);
                bool sc= (k-j)<=(n-1-k) && isEqual(j+1,k+1,k-j);
                if(fc||sc) ans++;
            }
        }
        return ans;
    }
};