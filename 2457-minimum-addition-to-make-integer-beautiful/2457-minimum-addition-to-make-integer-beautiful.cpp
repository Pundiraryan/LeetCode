class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long ans=0;
        string str=to_string(n);
        long long val=1;
        long long cs=0;
        for(auto &ch:str)cs+=(ch-'0');
        if(cs<=target)return 0;
        if((str[0]-'0')>=target){
            for(int i=0;i<str.length();i++){
                val=(long long)(val*10);
            }
            return val-n;
        }
        cs=(str[0]-'0');
        int idx=-1;
        for(int i=1;i<n;i++){
            cs+=(str[i]-'0');
            if(cs>=target){
                idx=i-1;
                break;
            }
        }
        // cout<<idx<<endl;
        val=(str[idx]-'0' +1);
        // cout<<val;
        for(int i=idx+1;i<str.length();i++){
            val=(long long)(val*10);
        }
        // cout<<val<<endl;
        long long num=stoll(str.substr(idx));
        // cout<<num<<endl;
        return val-num;
    }
};