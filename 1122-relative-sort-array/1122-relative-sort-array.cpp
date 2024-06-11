class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>res;
        unordered_map<int,int>fre;
        for(auto &x:arr1)fre[x]++;
        for(auto &x:arr2){
            while(fre[x]>0){
                res.push_back(x);
                fre[x]--;
            }
        }
        multiset<int>mst;
        for(auto &x:arr1){
            if(fre[x]>0)mst.insert(x);
        }
        for(auto &x:mst)res.push_back(x);
        return res;
    }
};