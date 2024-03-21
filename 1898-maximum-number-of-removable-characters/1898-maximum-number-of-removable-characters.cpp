class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        vector<char>vc;
        for(auto &x:removable)vc.push_back(s[x]);
        int l=0,r=vc.size();
        int ans=0;
        int n=s.length();
        while(l<=r){
            int mid=(l+r)>>1;
            string currs=s;
            for(int i=0;i<mid;i++)currs[removable[i]]='$';
            int pidx=0;
            for(int i=0;i<n;i++){
                if(currs[i]==p[pidx]){
                    pidx++;
                }
            }
            if(pidx==p.length()){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};