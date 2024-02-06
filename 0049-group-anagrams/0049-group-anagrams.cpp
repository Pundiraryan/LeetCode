class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>>ans;
        vector<pair<string,string>>vps;
        for(auto x:strs){
            string ns=x;
            sort(ns.begin(),ns.end());
            vps.push_back({ns,x});
        }
        sort(vps.begin(),vps.end());
        string fs=vps[0].first;
        ans.push_back({vps[0].second});
        for(int i=1;i<n;){
            int j=i;
            while(j<n && vps[j].first==fs){
                ans.back().push_back(vps[j].second);
                j++;
            }
            if(j==n)break;
            i=j;
            ans.push_back({});
            fs=vps[i].first;            
        }
        return ans;
    }
};