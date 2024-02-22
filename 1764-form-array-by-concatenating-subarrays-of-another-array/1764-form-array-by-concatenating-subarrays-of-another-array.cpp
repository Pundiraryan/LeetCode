class Solution {
public:
    void lps_func(vector<int>&txt, vector<int>&Lps){
    Lps[0] = 0;                   
    int len = 0;
    int i=1;
    while (i<txt.size()){
        if(txt[i]==txt[len]){   
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else{                   
            if(len==0){         
                Lps[i] = 0;
                i++;
                continue;
            }
            else{              
                len = Lps[len-1];
                continue;
            }
        }
    }
}
vector<int> kmp(vector<int>& pattern,vector<int>& text){
    int n = text.size();
    int m = pattern.size();
    vector<int>Lps(m);
    lps_func(pattern,Lps); 
    
    int i=0,j=0;
    int ans=0;
    vector<int>pos;
    while(i<n){
        if(pattern[j]==text[i]){i++;j++;} 
        if (j == m) { 
            pos.push_back(i-m);
            j = Lps[j - 1]; 
        } 
        else if (i < n && pattern[j] != text[i]) {  
            if (j == 0)i++;
            else j = Lps[j - 1]; 
        }
    }
    return pos;
}
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int g=groups.size(),n=nums.size();
        int pidx=-1;
        for(int i=0;i<g;i++){
            vector<int>pos=kmp(groups[i],nums);
            auto idx=upper_bound(pos.begin(),pos.end(),pidx);
            if(idx==pos.end())return false;
            pidx=*idx+groups[i].size()-1;
        }
        return true;
    }
};