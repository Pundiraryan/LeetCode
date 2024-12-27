class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int ans=-1;
        multiset<int>mst;
        for(int i=0;i<n;i++)mst.insert(values[i]-i);
        for(int i=0;i<n;i++){
            mst.erase(mst.find(values[i]-i));
            if(mst.empty())break;
            ans=max(ans,values[i]+i+*mst.rbegin());
        }
        return ans;
    }
};