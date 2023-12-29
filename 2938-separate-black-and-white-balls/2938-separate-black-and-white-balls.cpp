#define ll long long
class Solution {
public:
    long long minimumSteps(string s) {
        ll n=s.length();
        ll c1=0;
        ll ans=0;
        for(auto &x:s)c1+=(x=='1');
        unordered_set<int>st;
        for(ll i=n-1;i>=n-c1;i--){
            if(s[i]=='0')st.insert(i);
        }
        for(int i=0;i<n-c1;i++){
            if(s[i]=='1'){
                ans+=(*st.begin()-i);
                st.erase(st.begin());
            }
        }
        return ans;
    }
};