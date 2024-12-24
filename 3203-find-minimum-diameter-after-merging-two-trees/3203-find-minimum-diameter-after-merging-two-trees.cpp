    class Solution {
    public:
        void dfs(int node,int par,int cd,vector<int>&dis,vector<vector<int>>&graph){
            dis[node]=cd;
            for(auto &x:graph[node]){
                if(x==par)continue;
                dfs(x,node,1+cd,dis,graph);
            }
        }
        int diam(vector<vector<int>>&graph){
            int n=graph.size();
            vector<int>dis1(n);
            dfs(0,-1,0,dis1,graph);
            int nd=-1,mxd=-1;
            for(int i=0;i<n;i++){
                if(dis1[i]>mxd){
                    nd=i;
                    mxd=dis1[i];
                }
            }
            vector<int>dis2(n);
            dfs(nd,-1,0,dis2,graph);
            return *max_element(dis2.begin(),dis2.end());
        }
        int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
            int n=edges1.size()+1,m=edges2.size()+1;
            vector<vector<int>>graph1(n),graph2(m);
            for(auto &x:edges1){
                graph1[x[0]].push_back(x[1]);
                graph1[x[1]].push_back(x[0]);
            }
            for(auto &x:edges2){
                graph2[x[0]].push_back(x[1]);
                graph2[x[1]].push_back(x[0]); 
            }
            return max({diam(graph1),diam(graph2),1+(diam(graph1)+1)/2+(diam(graph2)+1)/2});
        }
    };