class Solution {
public:
long long MX = 999999999999;
    bool f(int i,long long pn,int cnt,string &s){
        int n=s.length();
        if(i==n && cnt>=2)return true;
        if(i==n)return false;
        bool anse=false;
        string ns="";
        long long  num=0;
        for(int j=i;j<n;j++){
            ns+=s[j];
            num=(long long )num*10+(s[j]-'0');
            if(num>MX)break;
            if(pn-num==1 || pn==-1000){
                anse=anse|f(j+1,num,cnt+1,s);
            }
        }
        return anse;
    }
    bool splitString(string s) {
        return f(0,-1000,0,s);
    }
};