class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int total=m*n;
        vector<vector<int>>vstd(m+1,vector<int>(n+1,0));
        vector<vector<int>>iswall(m+1,vector<int>(n+1,0));
        vector<vector<int>>isguard(m+1,vector<int>(n+1,0));
        for(auto &x:walls){
            iswall[x[0]][x[1]]=1;
        }
        for(auto &x:guards){
            isguard[x[0]][x[1]]=1;
        }
        int gone=walls.size();
        for(auto &x:guards){
            vstd[x[0]][x[1]]=1;
            gone++;
            int sx=x[0],sy=x[1]+1;
            while(sy<n && !iswall[sx][sy]  && !isguard[sx][sy]){
                if(vstd[sx][sy]){
                    sy++;continue;
                }
                vstd[sx][sy]=1;
                sy++;
                gone++;
            }
            sx=x[0],sy=x[1]-1;
            while(sy>=0 && !iswall[sx][sy]  && !isguard[sx][sy]){
                if(vstd[sx][sy]){
                    sy--;continue;
                }
                vstd[sx][sy]=1;
                sy--;
                gone++;
                
            }
            sx=x[0]+1,sy=x[1];
            while(sx<m && !iswall[sx][sy]  && !isguard[sx][sy]){
                if(vstd[sx][sy]){
                    sx++;continue;
                }
                 vstd[sx][sy]=1;
                sx++;
                gone++;
               
            }
            sx=x[0]-1,sy=x[1];
            while(sx>=0 && !iswall[sx][sy]  && !isguard[sx][sy]){
                if(vstd[sx][sy]){
                    sx--;continue;
                }
                vstd[sx][sy]=1;
                sx--;
                gone++;
           
            }
        }
        return total-gone;
    }
};