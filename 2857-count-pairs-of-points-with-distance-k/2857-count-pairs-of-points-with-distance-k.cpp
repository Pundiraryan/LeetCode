class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<pair<int,int>,int>fre;
        int ans=0;
        for(auto &x:coordinates){
            int xv=x[0],yv=x[1];
            for(int i=0;i<=k;i++){
                int x2=i^xv;
                int y2=(k-i)^yv;
                if(fre.find({x2,y2})!=fre.end())ans+=fre[{x2,y2}];
            }
            fre[{xv,yv}]++;
        }
        return ans;
    }
};