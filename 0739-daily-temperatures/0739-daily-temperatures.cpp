class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<int>st;
        vector<int>nge(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(!st.empty()){
                nge[i]=st.top();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(nge[i]==n)continue;
            ans[i]=nge[i]-i;
        }
        return ans;
    }
};