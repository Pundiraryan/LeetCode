class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans=0;
        unordered_map<long long,long long>fre;
        int p=33,mod=1e9+7;
        for(auto &x:words){
            int n=x.size();
            long long ph=0,sh=0,pv=1;
            for(int i=0;i<n;i++){
                ph=(ph*p+(x[i]-'a'+1))%mod;
                sh=(sh+((x[n-1-i]-'a'+1)*pv)%mod)%mod;
                pv=(pv*p)%mod;
                if(ph==sh){
                    ans=(ans+fre[ph]);
                }
            }
            fre[sh]++;
        }
        return ans;
    }
};