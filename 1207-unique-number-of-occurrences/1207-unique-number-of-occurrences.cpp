class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>fre;
        for(auto &x:arr)fre[x]++;
        unordered_set<int>st;
        for(auto &x:fre){
            if(st.find(x.second)!=st.end())return false;
            st.insert(x.second);
        }
        return true;
    }
};