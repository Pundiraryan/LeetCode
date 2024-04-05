class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int ans=1e9;
        int n=fronts.size();
        unordered_map<int,int>fre;
        for(int i=0;i<n;i++){
            fre[fronts[i]]++;
            fre[backs[i]]++;
        }
        vector<int>check(2005,0);
        for(int i=0;i<n;i++){
            if(fronts[i]==backs[i]){
                check[fronts[i]]=1;
            }
        }
        for(int i=1;i<=2000;i++){
            if(fre[i]>0 && !check[i]){
                ans=i;break;
            }
        }
        if(ans==1e9)return 0;
        return ans;
    }
};