class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        vector<pair<double,pair<int,int>>>vpp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double val=(double)((double)arr[i]/(double)arr[j]);
                vpp.push_back({val,{i,j}});
            }
        }
        sort(vpp.begin(),vpp.end());
        vector<int>res;
        res.push_back(arr[vpp[k-1].second.first]);
        res.push_back(arr[vpp[k-1].second.second]);
        return res;
    }
};