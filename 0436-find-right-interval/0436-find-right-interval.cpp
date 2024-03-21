class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
         int n=intervals.size();
        vector<int>res(n);
        map<pair<int,int>,int>fre;
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            fre[{intervals[i][0],intervals[i][1]}]=i;
            vp.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(vp.begin(),vp.end());
        for(int i=0;i<n;i++){
            pair<int,int>p={intervals[i][1],-1e9};
            auto idx=lower_bound(vp.begin(),vp.end(),p);
            if(idx==vp.end()){
                res[i]=-1;
            }else{
                res[i]=fre[*idx];
            }
        }
        
        return res;
    }
};