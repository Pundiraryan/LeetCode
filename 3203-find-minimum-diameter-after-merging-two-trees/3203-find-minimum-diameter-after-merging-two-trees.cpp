class Solution {
public:
    int bfs(int src,vector<int>&ans,vector<vector<int>>&graph){
        int val,n=graph.size();
        queue<int>q;
        vector<int>d(n+1,-1);
        d[src]=0;
        ans[src]=max(ans[src],d[src]);
        q.push(src);
        while(!q.empty()){
            val=q.front();
            q.pop();
            for(auto x:graph[val]){
                if(d[x]==-1){
                    q.push(x);
                    d[x]=1+d[val];
                    ans[x]=max(ans[x],1+d[x]);
                }
            }
        }
        return val;
}
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1,m=edges2.size()+1;
        // if(n==1 && m==1)return 1;
        vector<vector<int>>graph1(n),graph2(m);
        for(auto &x:edges1){
            graph1[x[0]].push_back(x[1]);
            graph1[x[1]].push_back(x[0]);
        }
        for(auto &x:edges2){
            graph2[x[0]].push_back(x[1]);
            graph2[x[1]].push_back(x[0]);
        }
        vector<int>ans(n,-1);
        int fn=bfs(0,ans,graph1);
        int sfn=bfs(fn,ans,graph1);
        bfs(sfn,ans,graph1);
        vector<int>md1(n);
        for(int i=0;i<n;i++)if(ans[i])md1[i]=ans[i]-1;
        vector<int>ans1(m,-1);
        int fn1=bfs(0,ans1,graph2);
        int sfn1=bfs(fn1,ans1,graph2);
        bfs(sfn1,ans1,graph2);
        vector<int>md2(m);
        for(int i=0;i<m;i++)if(ans1[i])md2[i]=ans1[i]-1;
        sort(md1.begin(),md1.end());
        sort(md2.begin(),md2.end());
        // cout<<md1[0]<<" || "<<md2[0]<<endl;
        return max({md1.back(),md2.back(), md1.front()+md2.front()+1});
    }
};