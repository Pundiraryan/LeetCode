class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<unordered_map<int,int>>fre(n);
        for(int i=0;i<n;i++){
            int cx=0;
            for(int j=i;j<n;j++){
                cx^=arr[j];
                fre[i][cx]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int cx=0;
            for(int j=i+1;j<n;j++){
                cx^=arr[j-1];
                ans+=fre[j][cx];
            }
        }
        return ans;
    }
};