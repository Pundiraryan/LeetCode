class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int ans=0;
        vector<int>cnt(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<bank[i].size();j++){
                cnt[i]+=(bank[i][j]=='1');
            }
        }
        for(int i=0;i<n;i++){
            if(!cnt[i])continue;
            for(int j=i+1;j<n;j++){
                if(!cnt[j])continue;
                ans+=(cnt[i]*cnt[j]);
                break;
            }
        }
        return ans;
    }
};