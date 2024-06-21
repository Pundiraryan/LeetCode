class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n= customers.size();
        int minans=0;
        for(int i=0;i<n;i++){
            if(!grumpy[i])minans+= customers[i];
        }
        int maxi=0,extra=0,s=0,e=0;
        while(e<n){
            if(grumpy[e]==1){
                extra+= customers[e];
            }
            if(e-s+1 >minutes){
                if(grumpy[s]==1){
                    extra-= customers[s];
                }
                s++;
            }
            maxi= max(maxi, extra);
            e++;
        }
        return minans+maxi;
    }
};