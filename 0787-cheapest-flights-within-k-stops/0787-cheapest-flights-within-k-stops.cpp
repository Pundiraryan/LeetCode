class Solution {
public:
    int dijkstra(int src,int dst,int k, vector<vector<pair<int,int>>>&graph){
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,src}});
        int n=graph.size();
        vector<int>dist(n,1e9);
        dist[src]=0;
         pq.push({0, {0, src}});    
        while(!pq.empty())  {
            auto curr = pq.top();
            int stop = curr.first, cost = curr.second.first, node = curr.second.second;
            pq.pop();
            if(node == dst || stop > k)continue;
            for(auto &x :graph[node])    {
                int newnode = x.first, dis = x.second;
                if(cost + dis < dist[newnode])   {
                    dist[newnode] = cost + dis;
                    pq.push({stop+1, {dist[newnode], newnode}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto &x:flights){
            int from=x[0],to=x[1],cost=x[2];
            graph[from].push_back({to,cost});
        }
        return dijkstra(src,dst,k,graph);
    }
};