class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>ans(n,0);
        vector<int>nge(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]<=heights[i])st.pop();
            if(!st.empty()){
                nge[i]=st.top();
            }
            st.push(i);
        }
        for(int i=0;i<n-1;i++){
            int j=i+1;
            int cans=0;
            while(j>=0 && j<n){
                cans++;
                if(heights[j]>heights[i])break;
                j=nge[j];
            }
            ans[i]=cans;
        }
        return ans;
    }
};