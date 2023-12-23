class Solution {
public:
    bool check(char c){
        return c=='a' || c=='e' || c=='i' ||c=='o' ||c=='u';
    } 
    int beautifulSubstrings(string s, int k) {
        int n=s.length();
        int res=0;
        for(int i=0;i<n;i++){
            int vc=0,cc=0;
            for(int j=i;j<n;j++){
                vc+=(check(s[j]));
                cc=(j-i+1)-vc;
                if(vc==cc &&(vc*cc)%k==0)
                {
                    res++;
                }
            }
        }
        return res;
    }
};