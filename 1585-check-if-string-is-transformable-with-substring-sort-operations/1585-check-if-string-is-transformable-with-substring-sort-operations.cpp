class Solution {
public:
    bool isTransformable(string s, string t) {
        int n=s.length();
        vector<deque<int>>pos(10);
        for(int i=0;i<n;i++){
            pos[s[i]-'0'].push_back(i);
        }
        for(int i=0;i<n;i++){
            if(pos[t[i]-'0'].empty())return false;
            int minpos=pos[t[i]-'0'].front();
            for(int j=0;j<(t[i]-'0');j++){
                if(!pos[j].empty() && pos[j].front()<minpos)return false;
            }
            pos[t[i]-'0'].pop_front();
        }
        return true;
    }
};