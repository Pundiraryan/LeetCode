class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans=0;
        vector<int>freq(n,0);
        for(auto &x:roads){
            freq[x[0]]++;
            freq[x[1]]++;
        }
        sort(freq.rbegin(),freq.rend());
        for(int i=0;i<n;i++){
            ans+=(long long)(n-i)*freq[i];
        }
        return ans;
    }
};