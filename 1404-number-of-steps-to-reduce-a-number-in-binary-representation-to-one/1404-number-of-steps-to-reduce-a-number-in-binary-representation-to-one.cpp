class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        while(s!="1"){
            if(s[s.length()-1]=='0')s.pop_back();
            else{
                s[s.length()-1]='0';
                bool done=false;
                for(int i=s.length()-2;i>=0;i--){
                    if(s[i]=='1')s[i]='0';
                    else{
                        done=true;
                        s[i]='1';
                        break;
                    }
                }
                if(!done){
                    s.insert(s.begin(),1,'1');
                }
            }
            ans++;
        }
        return ans;
    }
};