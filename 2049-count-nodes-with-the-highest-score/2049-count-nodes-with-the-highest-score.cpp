class Solution {
public:
    int precomp(int src,int par,vector<int>&sz,vector<vector<int>>&graph){
        int val=1;
        for(auto &x:graph[src]){
            if(x==par)continue;
            val+=precomp(x,src,sz,graph);
        }
        
        return sz[src]=val;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<vector<int>>graph(n);
        for(int i=1;i<n;i++){
            graph[parents[i]].push_back(i);
            // graph[i].push_back(parents[i]);
        }
        vector<int>sz(n);
        precomp(0,-1,sz,graph);
        vector<long long>sc(n);
        long long mc=0,ans=0;
        for(int i=0;i<n;i++){
            long long is=1;
            is = max(is, (long long)(n - sz[i]));
            for(auto &x:graph[i]){
                is*=(long long)(sz[x]);
            }
            if(is>mc){
                mc = is;
                ans=1;
            }
            else if(is==mc){
                ans++;
            }
        }
        return ans;
    }
};