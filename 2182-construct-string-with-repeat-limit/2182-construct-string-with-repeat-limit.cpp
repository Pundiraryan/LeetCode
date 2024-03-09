class Solution {
public:
    string repeatLimitedString(string s, int rl) {
        int n=s.length();
        vector<int>fre(26,0);
        for(auto &ch:s)fre[ch-'a']++;
        string ans="";
        int rc=24;
        for(int i=25;i>=0;i--){
            rc=i-1;
            if(fre[i]<=rl){
                ans+=string(fre[i],'a'+i);
            }else{
                while(fre[i]>0){
                    ans+=string(min(fre[i],rl),'a'+i);
                    fre[i]-=min(fre[i],rl);
                    if(fre[i]<=0)break;
                    while(rc >=0 && fre[rc]==0)rc--;
                    if(rc<0)break;
                    ans.push_back('a'+rc);
                    fre[rc]--;
                }
                
            }
        }
        return ans;
        
    }
};