#define mod 12345
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>res(n,vector<int>(m));
        vector<int>left(n*m,1),right(n*m,1);
        long long curr=grid[0][0];
        for(int i=1;i<n*m;i++){
            left[i]=curr;
            curr=(curr%mod*grid[i/m][i%m]%mod)%mod;
        }
     
        curr=grid[n-1][m-1];
        for(int i=n*m-2;i>=0;i--){
            right[i]=curr;
            curr=(curr%mod*(grid[i/m][i%m])%mod)%mod;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long val=1;
                val*=(left[i*m+j])%mod;
                val*=(right[i*m+j])%mod;
                val%=mod;
                res[i][j]=val;
            }
        }
        return res;
    }
};