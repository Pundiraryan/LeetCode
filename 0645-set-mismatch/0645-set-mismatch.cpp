class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int es=(n*(n+1))/2;
        long long ess=((long long)n*(long long)(n+1)*(long long)(2*n+1))/6;
        int cs=0;
        long long css=0;
        for(auto &x:nums){
            cs+=x;
            css+=x*x;
        }
        es-=cs;
        ess-=css;
        int addval=ess/es;
        int val=(addval-es)/2,val2=(addval+es)/2;
        return {val,val2};
        
        
        
    }
};