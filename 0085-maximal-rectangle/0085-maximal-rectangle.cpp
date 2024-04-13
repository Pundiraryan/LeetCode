class Solution {
public:
    int f(vector<int>&nums){
        stack<int>st;
        int n=nums.size();
        n--;
        vector<int>nse(n,n);
        vector<int>pse(n,-1);
        int mv=0;
        stack<int>st1;
        for(int i=0;i<n;i++){
            while(!st1.empty() && nums[st1.top()]>=nums[i]){
                st1.pop();
            }
             if(!st1.empty()){
                pse[i]=st1.top();
            }
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i]=st.top();
            }
            st.push(i);
        }

        for(int i=0;i<n;i++){
            mv=max(mv,(nse[i]-pse[i]-1)*nums[i]);
        }
        return mv;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        vector<vector<int>>dp(r+1,vector<int>(c+1,0));
        for(int i=r-1;i>=0;i--){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=1+dp[i+1][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<r;i++){
            int val=f(dp[i]);
            ans=max(ans,val);
        }
        return ans;
    }
};