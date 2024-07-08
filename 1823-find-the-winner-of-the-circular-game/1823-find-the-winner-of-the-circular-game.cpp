class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>ans(n);
        for(int i=0;i<n;i++)ans[i]=i+1;
        int curr=0;
        while(ans.size()>1){
            curr=(curr+k-1)%ans.size();
            ans.erase(ans.begin()+curr);
        }
        return ans[0];
    }
};