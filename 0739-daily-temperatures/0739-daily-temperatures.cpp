class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
        ans[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int j=i+1;
            while(j<n && temperatures[j]<=temperatures[i]){
                if(ans[j]==0)break;
                j+=ans[j];
            }
            if(j>=n){
                ans[i]=0;
            }else{
                if(temperatures[j]<=temperatures[i])ans[i]=0;
                else ans[i]=j-i;
            }
        }
        
        return ans;
    }
};