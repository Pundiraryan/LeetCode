class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            char chp=s[i],chl=s[j];
            if(chp!=chl)break;
            while( i<j && s[i]==chp)i++;
            while(j>=0 && s[j]==chl)j--;
        }
        return max(j-i+1,0);
    }
};