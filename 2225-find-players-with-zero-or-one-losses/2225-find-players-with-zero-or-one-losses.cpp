class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans;
        set<int>p;
        unordered_map<int,int>lc;
        for(auto &x:matches){
            p.insert(x[0]);
            p.insert(x[1]);
            lc[x[1]]++;
        }
        vector<int>nl,ol;
        for(auto &x:p){
            if(lc[x]==0)nl.push_back(x);
            else if(lc[x]==1)ol.push_back(x);
        }
        ans={nl,ol};
        return ans;
    }
};