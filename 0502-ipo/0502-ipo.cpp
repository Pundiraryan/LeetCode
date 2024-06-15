class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // multiset<pair<int,int>>mst;
        int n=capital.size();
        vector<pair<int,int>>vp(n);
        for(int i=0;i<n;i++)vp[i]={capital[i],profits[i]};
        sort(vp.begin(),vp.end());
        int ptr=0;
        priority_queue<int>pq;
        for(int i=0;i<k;i++){
           while(ptr<n && vp[ptr].first<=w){
               pq.push(vp[ptr].second);
               ptr++;
           }
            if(pq.empty())break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};