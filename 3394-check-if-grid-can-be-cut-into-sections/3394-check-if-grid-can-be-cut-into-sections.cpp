class Solution {
public:
    bool merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
        merged.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    return merged.size()>=3;
}
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>i1,i2;
        for(auto &x:rectangles){
            i1.push_back({x[0],x[2]});
            i2.push_back({x[1],x[3]});
        }
        return merge(i1)||merge(i2);
         
    }
};