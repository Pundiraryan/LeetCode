#define ll long long
#define mod 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>pse(n,-1),nse(n,n);
        stack<int>st,st1;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top();
            }
            st.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && arr[i]<arr[st1.top()]){
                st1.pop();
            }
            if(!st1.empty()){
                nse[i]=st1.top();
            }
            st1.push(i);
        }
        ll answer=0;
        for(int i=0;i<n;i++){
            int cnt1=i-pse[i],cnt2=nse[i]-i;
            ll addval=((cnt1)*(cnt2))%mod;
            addval=(addval*arr[i])%mod;
            answer=(answer+addval)%mod;
        }
        return answer;
    }
};