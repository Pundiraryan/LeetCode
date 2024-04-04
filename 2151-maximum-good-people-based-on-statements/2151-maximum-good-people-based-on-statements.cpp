class Solution {
public:
    bool check(int mask,vector<vector<int>>&statements){
        int n=statements.size();
       for(int i=0;i<n;i++){
        if(((1<<i)&mask)){
            for(int j=0;j<n;j++){
                int good=(mask>>j) &1;
                if(statements[i][j]==0 && good)return false;
                if(statements[i][j]==1 && !good)return false;
            }
        }
       }
        return true;
        
    }
    int maximumGood(vector<vector<int>>& statements) {
       int ans=0,n=statements.size();
        for(int mask=((1<<n)-1);mask>=1;mask--){
            if(check(mask,statements))ans=max(ans,__builtin_popcount(mask));
        }
        return ans;
    }
};