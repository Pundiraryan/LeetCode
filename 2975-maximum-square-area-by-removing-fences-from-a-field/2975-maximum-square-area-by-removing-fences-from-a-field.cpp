#define mod 1000000007
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int>st;
        hFences.push_back(1);hFences.push_back(m);
        vFences.push_back(1);vFences.push_back(n);
        for(int i=0;i<hFences.size();i++){
            for(int j=0;j<hFences.size();j++){
                st.insert(abs(hFences[i]-hFences[j]));
            }
        }
        long long ans=0;
        for(int i=0;i<vFences.size();i++){
            for(int j=0;j<vFences.size();j++){
                if(j==i)continue;
                if(st.find(abs(vFences[i]-vFences[j]))!=st.end()){
                    ans=max(ans,(long long)(vFences[i]-vFences[j]));
                }
            }
        }
        if(ans==0)return -1;
        return (ans*ans)%mod;
    }
};