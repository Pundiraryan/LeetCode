class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int>ans;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int med=arr[(n-1)/2];
        vector<pair<int,int>>vps;
        for(int i=0;i<n;i++){
            vps.push_back({abs(arr[i]-med),arr[i]});
        }
        sort(vps.begin(),vps.end());
        reverse(vps.begin(),vps.end());
        for(int i=0;i<k;i++)ans.push_back(vps[i].second);
        return ans;
    }
};