class Solution {
public:
    int popchar(string &s,string ps,int cs){
        stack<char>st;
        int c1=0;
        for(auto &x:s){
            if(st.empty()){
                st.push(x);
            }else{
                if(x==ps[1] && !st.empty() && st.top()==ps[0]){
                    st.pop();
                    c1+=cs;
                }else{
                    st.push(x);
                }
            }
        }
        string temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(begin(temp),end(temp));
        s=temp;
        return c1;
    }
    int maximumGain(string s, int cx, int cy) {
        int ans=0;
        string fs="ab",ss="ba";
        if(cx>cy){
            ans+=popchar(s,fs,cx);
            ans+=popchar(s,ss,cy);
        }else{
            ans+=popchar(s,ss,cy);
            ans+=popchar(s,fs,cx);
        }
        return ans;
    }
};