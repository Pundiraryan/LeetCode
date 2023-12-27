class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        int ans=0;
        int i=0;
        while(i<n){
            int mx=0,csum=0,j=i;
            char clr=colors[i];
            while(j<n && colors[j]==clr){
                mx=max(mx,neededTime[j]);
                csum+=neededTime[j];
                j++;
            }
            if(csum>0)ans+=(csum-mx);
            if(j==i)i++;
            else i=j;
        }
        return ans;
    }
};