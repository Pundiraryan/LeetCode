class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        vector<vector<int>>ps(n,vector<int>(n+2,0));
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0],b=queries[i][1],c=queries[i][2],d=queries[i][3];
            for(int j=a;j<=c;j++){
                ps[j][b]++;
                ps[j][d+1]--;
            }
        }
        for(int i=0;i<n;i++){
            int val=0;
            for(int j=0;j<n;j++){
                val+=ps[i][j];
                ans[i][j]=val;
            }
        }
        return ans;
    }
};