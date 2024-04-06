class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        if(changed.size()%2!=0)return {};
        unordered_map<int,int>fre;
        for(auto &x:changed)fre[x]++;
        vector<int>res;
        for(auto &x:changed){
            if(fre.find(x)==fre.end())continue;
            if(fre.find(2*x)==fre.end())return {};
            res.push_back(x);
            fre[x]--;
            if(fre[x]==0)fre.erase(x);
            fre[x*2]--;
            if(fre[x*2]==0)fre.erase(2*x);
        }
        cout<<res.size()<<endl;
        if(res.size()!=changed.size()/2)return {};
            return res;
    }
};