class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n=arr.size();
        vector<long long>ans(n);
        map<int,vector<int>>fre;
        for(int i=0;i<n;i++){
            fre[arr[i]].push_back(i);
        }
        for(auto &x:fre){
            int num=x.first;
            vector<int>poss=x.second;
            for(auto &y:poss){
                ans[poss[0]]+=(long long)abs(y-poss[0]);
            }
        }
        for(auto &x:fre){
             int num=x.first;
            vector<int>poss=x.second;
            for(int i=1;i<poss.size();i++){
                ans[poss[i]]=ans[poss[i-1]]-(poss[i]-poss[i-1])*(poss.size()-i-1)+(poss[i]-poss[i-1])*(i-1);
            }
        }
        return ans;
    }
};