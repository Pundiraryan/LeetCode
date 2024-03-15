class Solution {
public:
    int minMovesToMakePalindrome(string s) {
         int n=s.length(),i=0,j=n-1;
        int ans=0;
        while(i<j){
            int k=i;
            while(s[k]!=s[j])k++;
            if(k==j){
                ans++;
                swap(s[k],s[k-1]);
            }else{
                while(k>i){
                    ans++;
                    swap(s[k],s[k-1]);
                    k--;
                }
                i++;j--;
            }
        }
        return ans;
    }
};