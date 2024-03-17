class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n=word.length();
        map<char,int>fre;
        for(auto &x:word)fre[x]++;
        vector<int>v;
        for(auto &x:fre)v.push_back(x.second);
        sort(v.rbegin(),v.rend());
        int ans=1e9;
        for(int i=0;i<v.size();i++){
            int curr=0;
            for(int val:v){
                if(val>v[i]+k){
                    curr+=(val-(v[i]+k));
                }else if(val<v[i]){
                    curr+=val;
                }
            }
            ans=min(ans,curr);
            if(ans==0)break;
        }
        if(ans==1e9)return 0;
        return ans;
        
    }
};