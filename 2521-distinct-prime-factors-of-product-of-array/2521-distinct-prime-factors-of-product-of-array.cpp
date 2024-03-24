class Solution {
public:
     vector<int>spf;
 
 void sieve(int n)
{
    spf[1] = 1;
    for (int i = 2; i < n; i++)spf[i] = i;
    for (int i = 4; i < n; i += 2)spf[i] = 2;
    for (int i = 3; i * i < n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < n; j += i){
                if (spf[j] == j)spf[j] = i;
            }
        }
    }
}
 
unordered_set<int> factorise(int x)
{
    unordered_set<int> ret;
    while (x != 1) {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
    int distinctPrimeFactors(vector<int>& nums) {
        int mv=*max_element(nums.begin(),nums.end());
        spf.resize(mv+2);
        sieve(mv+1);
        unordered_set<int>df;
        for(auto &x:nums){
            unordered_set<int>nf=factorise(x);
            for(auto &fac:nf){
                if(df.find(fac)!=df.end())continue;
                df.insert(fac);
            }
        }
        return (int)df.size();
    }
};