class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int>tarr;
        for(int i=0;i<n;i++)tarr.push_back((dist[i]+speed[i]-1)/speed[i]);
        sort(tarr.begin(),tarr.end());
        int ans=0;
        int pv=1;
        for(int i=0;i<n;i++){
            if(tarr[i]>=pv){
                ans++;
                pv++;
            }else{

                break;
            }
        }
        return ans;
    }
};