class Solution {
public:

 int kmp(string& pat, string& str) {
    int M = pat.length();
    int N = str.length();
  
    int lps[M];
    computeLPSArray(pat, M, lps);
  
    int i = 0; 
    int j = 0;
     int ans=0;
    while (i < N) {
        if (pat[j] == str[i]) {
            j++;
            i++;
        }
  
        if (j == M) {
            ans++;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != str[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
     return ans;
}
  
void computeLPSArray(string& pat, int M, int* lps) {
        int len = 0;
  
    lps[0] = 0;   
       int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else{
           if (len != 0) {
                len = lps[len - 1];
           }
            else             {
                lps[i] = 0;
                i++;
            }
        }
    }
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