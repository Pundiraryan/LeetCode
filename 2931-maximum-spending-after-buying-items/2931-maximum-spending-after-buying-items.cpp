#define ll long long
class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        ll res=0;
        vector<int>ans;
        for(auto &x:values){
            for(auto &y:x){
                ans.push_back(y);
            }

        }
        sort(ans.begin(),ans.end());
        ll d=1;
        for(auto &x:ans){
            res+=x*d;
            d++;
        }
        return res;
    }
};