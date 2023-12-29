class Solution {
public:
    int conv(string &s){
        return 1000*(s[0]-'0')+100*(s[1]-'0')+10*(s[2]-'0')+(s[3]-'0');
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string>ans;
        map<string,multiset<int>>fre;
        for(auto &x:access_times){
            fre[x[0]].insert(conv(x[1]));
        }
        for(auto &x:fre){
            auto y=x.second;
            auto eidx=y.end();
            eidx--;eidx--;
            for(auto idx=y.begin();(idx)!=eidx;idx++){
                auto idx1=idx;idx1++;idx1++;
                if(*idx1-*idx<100){
                    ans.push_back(x.first);break;
                }
            }
        }
        return ans;
    }
};