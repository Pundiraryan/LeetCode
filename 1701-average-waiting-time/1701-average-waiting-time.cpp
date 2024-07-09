class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int sz=customers.size();
        double ans=0;
        double ctot=0;
        for(auto &x:customers){
            if(ctot>=x[0]){
                ctot=ctot+x[1];
                ans+=(ctot-(double)x[0]);
            }
            else{
                ans+=(double)x[1];
                ctot=(x[0]+x[1]);
            }
        }
        return (double)ans/(double)sz;
    }
};