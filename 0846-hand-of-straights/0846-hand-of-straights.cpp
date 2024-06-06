class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;       int n=hand.size();
        if(n%groupSize!=0)return false;
        unordered_map<int,int>fre;
        set<int>st;
        for(auto x:hand){
            fre[x]++;
            st.insert(x);
        }
        for(auto x:st)pq.push({x,fre[x]});
        vector<int>res;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            if(res.size()!=0){
                if(res.back()+1!=curr.first)return false;   
            }
            res.push_back(curr.first);
            fre[curr.first]--;
            if(res.size()==groupSize){
                for(auto x:res){
                    if(fre[x]>=1){
                        pq.push({x,fre[x]});
                    }
                }
                res.clear();
            }
        }
        return res.empty();
    }
};