vector<pair<int,int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
public:
    vector<vector<int>> nd(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        vector<vector<int>>dist(r,vector<int>(c));
        vector<vector<int>>vstd(r,vector<int>(c));
        queue<pair<pair<int,int>,int>>bfs;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==1){
                    bfs.push({{i,j},0});
                    vstd[i][j]=1;
                }
            }
        }
        while(!bfs.empty()){
            auto curr=bfs.front();
            bfs.pop();
            int xc=curr.first.first;
            int yc=curr.first.second;
            int dis=curr.second;
            dist[xc][yc]=dis;
            for(auto &d:dirs){
                int nx=xc+d.first;
                int ny=yc+d.second;
                if(nx>=0 && nx<r && ny>=0 && ny<c && !vstd[nx][ny]){
                    bfs.push({{nx,ny},dis+1});
                    vstd[nx][ny]=1;
                }
            }
        }
        return dist;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>>md=nd(grid);
        int ans=0;
        int l=0,r=1e9;
        auto check=[&](int mid,vector<vector<int>>&md){
             queue<pair<int,int>>bfs;
            int r=md.size(),c=md.size();
            if(md[0][0]<mid)return false;
            vector<vector<int>>vstd(r,vector<int>(c,0));
            bfs.push({0,0});
            vstd[0][0]=1;
        while(!bfs.empty()){
            auto curr=bfs.front();
            bfs.pop();
            int xc=curr.first;
            int yc=curr.second;
            if(xc==r-1 && yc==c-1){
                return true;
            }
            for(auto &d:dirs){
                int nx=xc+d.first;
                int ny=yc+d.second;
                if(nx>=0 && nx<r && ny>=0 && ny<c && !vstd[nx][ny] && md[nx][ny]>=mid){
                    bfs.push({nx,ny});
                    vstd[nx][ny]=1;
                }
            }
        }
        return false;
        };
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,md)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};