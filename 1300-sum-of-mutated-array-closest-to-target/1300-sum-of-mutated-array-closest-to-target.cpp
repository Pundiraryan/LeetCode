class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int ans=1e9,mv=1e9;
        int n=arr.size();
        int r=*max_element(arr.begin(),arr.end());
        vector<int>ps(n);
        sort(arr.begin(),arr.end());
        ps[0]=arr[0];
        for(int i=1;i<n;i++)ps[i]=(ps[i-1]+arr[i]);
        for(int i=0;i<=r;i++){
            int gn=arr.end()-upper_bound(arr.begin(),arr.end(),i);
            int ns=i*gn;
            if(n-1-gn>=0){
                ns+=ps[n-1-gn];
            }
            int diff=abs(target-ns);
            if(diff<mv){
                ans=i;
                mv=diff;
            }
        }
        return ans;
    }
};