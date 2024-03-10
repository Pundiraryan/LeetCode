class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        sort(happiness.rbegin(),happiness.rend());
        int n=happiness.size();
        int ptr=0;
        for(int i=0;i<k;i++){
            ans+=max(happiness[ptr]-i,0);
            ++ptr;
        }
        return ans;
    }
};