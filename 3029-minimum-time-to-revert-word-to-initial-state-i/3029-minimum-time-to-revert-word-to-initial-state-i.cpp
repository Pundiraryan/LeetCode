class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.length();
        unordered_set<string>pre;
        string curr="";
        pre.insert(curr);
        for(int i=0;i<n;i++){
            curr.push_back(word[i]);
            pre.insert(curr);
        }
        int ans=1;
        for(int i=0;i<n;i+=k){
            if(i+k>=n)break;
            int nidx=i+k;
            string nstr=word.substr(i+k);
            if(pre.find(nstr)==pre.end())ans++;
            else{
                break;
            }
        }
        return ans;
    }
};