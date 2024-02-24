class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto &x:meetings){
            graph[x[0]].push_back({x[2],x[1]});
            graph[x[1]].push_back({x[2],x[0]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        pq.push({0,firstPerson});
        unordered_set<int>vstd;
        vector<int>ans;
        while(!pq.empty()){
            auto curr=pq.top();pq.pop();
            int mt=curr.first;
            int person=curr.second;
            if(vstd.find(person)!=vstd.end())continue;
            vstd.insert(person);
            for(auto &pm:graph[person]){
                int mtt=pm.first,mtp=pm.second;
                if(vstd.find(mtp)!=vstd.end())continue;
                if(mtt>=mt){
                    pq.push({mtt,mtp});
                }
            }
        }
        for(auto &x:vstd)ans.push_back(x);
        return ans;
    }
};