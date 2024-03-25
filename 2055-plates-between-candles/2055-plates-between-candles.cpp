class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.length();
        vector<int>cp;
        for(int i=0;i<n;i++){
            if(s[i]=='|')cp.push_back(i);
        }
        vector<int>ps(n,0);
        if(s[0]=='*')ps[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]=='*')ps[i]=ps[i-1]+1;
            else ps[i]=ps[i-1];
        }
        vector<int>ans((int)queries.size(),0);
        if(cp.empty())return ans;
        for(int i=0;i<queries.size();i++){
            int ll=queries[i][0];
            int ul=queries[i][1];
            int lidx=lower_bound(cp.begin(),cp.end(),ll)-cp.begin();
            int ridx=upper_bound(cp.begin(),cp.end(),ul)-cp.begin();
             if(lidx<0 || lidx>=cp.size() || ridx<=0 || ridx>cp.size() || ps[cp[ridx-1]]-ps[cp[lidx]]<0)continue;
          else ans[i]=(ps[cp[ridx-1]]-ps[cp[lidx]]);
           
        }
        return ans;
    }
};