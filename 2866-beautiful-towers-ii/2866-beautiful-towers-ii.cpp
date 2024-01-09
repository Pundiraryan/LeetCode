#define ll long long
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        ll n=maxHeights.size();
        ll ans=0;
        stack<ll>st;
        vector<ll>dpl(n,0),dpr(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && maxHeights[i]<=maxHeights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                dpl[i]=max(dpl[i],(ll)(i-st.top())*(ll)maxHeights[i]+dpl[st.top()]);
            }else{
                dpl[i]=(ll)(i+1)*(ll)maxHeights[i];
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && maxHeights[i]<=maxHeights[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                dpr[i]=max(dpr[i],(ll)(st.top()-i)*(ll)maxHeights[i] +dpr[st.top()]);
            }else{
                dpr[i]=(ll)(n-i)*(ll)maxHeights[i];
            }
            st.push(i);
        }
        ans=max(ans,max(dpl[n-1],dpr[0]));
        for(ll i=0;i<n-1;i++){
            ans=max(ans,dpl[i]+dpr[i+1]);
        }
        return ans;
    }
};