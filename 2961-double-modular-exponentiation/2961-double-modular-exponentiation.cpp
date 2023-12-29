#define ll int
class Solution {
public:
    ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result
    x = x % p; // Update x if it is more than or equal to p
    while (y > 0)
    {
    // If y is odd, multiply x with result
    if (y & 1)
    res = (res * x) % p;
    // y must be even now
    y = y >> 1; // y = y/2
    x = (x * x) % p;
    }
    return res;
}
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {    
        vector<int>ans;
        for(int i=0;i<variables.size();i++){
            int a=variables[i][0],b=variables[i][1],c=variables[i][2],d=variables[i][3];
            int val=power(a,b,10);
            int fv=power(val,c,d);
            if(target==fv)ans.push_back(i);
        }
        return ans;
        
    }
};