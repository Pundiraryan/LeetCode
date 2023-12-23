class Solution {
public:
    bool isPathCrossing(string path) {
        int n=path.length();
        int cx=0,cy=0;
        set<pair<int,int>>vstd;
        for(int i=0;i<n;i++){
            vstd.insert({cx,cy});
            if(path[i]=='N')cy++;
            if(path[i]=='S')cy--;
            if(path[i]=='E')cx++;
            if(path[i]=='W')cx--;
            if(vstd.find({cx,cy})!=vstd.end())return true;
        }
        return false;
    }
};