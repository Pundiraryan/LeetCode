class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>ans;
        vector<int>aidx,bidx;
        for(int i=0;i<s.length();i++){
            string str="";
            if(i+a.length()-1==s.length())break;
            for(int j=0;j<a.length();j++){
                str.push_back(s[i+j]);
            }
            if(str==a)aidx.push_back(i);
        }
       for(int i=0;i<s.length();i++){
            string str="";
           if(i+b.length()-1==s.length())break;
            for(int j=0;j<b.length();j++){
                str.push_back(s[i+j]);
            }
            if(str==b)bidx.push_back(i);
        }
        for(int i=0;i<aidx.size();i++){
            if(bidx.empty())break;
            auto idx=upper_bound(bidx.begin(),bidx.end(),aidx[i]+k);
            if(idx!=bidx.begin()){
                auto pidx=prev(idx);
                if(*pidx>=(aidx[i]-k)){
                    ans.push_back(aidx[i]);
                }
            }
        }
        
        return ans;
    }
};