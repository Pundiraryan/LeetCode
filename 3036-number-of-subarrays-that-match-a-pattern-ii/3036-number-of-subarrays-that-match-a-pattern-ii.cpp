class Solution {
public:
void lps_func(string txt, vector<int>&Lps){
    Lps[0] = 0;                   
    int len = 0;
    int i=1;
    while (i<txt.length()){
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
int kmp(string pattern,string text){
    int n = text.length();
    int m = pattern.length();
    vector<int>Lps(m);
    lps_func(pattern,Lps); 
    
    int i=0,j=0;
    int ans=0;
    while(i<n){
        if(pattern[j]==text[i]){i++;j++;} 
        if (j == m) { 
            ans++;
            // cout<<i - m <<' ';  
            j = Lps[j - 1]; 
        } 
        else if (i < n && pattern[j] != text[i]) {  
            if (j == 0)i++;
            else j = Lps[j - 1]; 
        }
    }
    return ans;
}
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int ans=0;
        vector<int>nnums;
        int n=nums.size();
        string ms="";
        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i])ms.push_back('a');
            else if(nums[i+1]==nums[i])ms.push_back('b');
            else ms.push_back('c');
        }
        string patt="";
        for(int i=0;i<pattern.size();i++){
            if(pattern[i]==1)patt.push_back('a');
            else if(pattern[i]==0)patt.push_back('b');
            else patt.push_back('c');
        }
        
        cout<<ms<<" "<<patt<<endl;
    
        
        return kmp(patt,ms);
        
    }
};