#define pii pair<int,pair<int,int>>
class Solution {
public:

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>res(queries.size(),0);
        vector<pair<int,int>>new_query(queries.size());
        for(int i=0;i<queries.size();++i){
            new_query[i]={queries[i],i};
        }
        sort(new_query.begin(),new_query.end());
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;

        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int point=0;
        for(int ind=0;ind<new_query.size();++ind){
            int maxi=new_query[ind].first;
            int index=new_query[ind].second;
            
            while(!pq.empty() && pq.top().first<maxi){
                point++;
                int i=pq.top().second.first;
                int j=pq.top().second.second;
                pq.pop();
                for(int k=0;k<4;++k){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && vis[ni][nj]==0){
                        pq.push({grid[ni][nj],{ni,nj}});
                        vis[ni][nj]=1;
                    }
                }
            }
            res[index]=point;
        }
        return res;
    }
};