class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto pos=lower_bound(intervals.begin(),intervals.end(),newInterval);
        intervals.insert(pos,newInterval);
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=res.back()[1]){
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};