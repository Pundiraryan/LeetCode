class Solution {
public:
    int countCollisions(string dirs) {
        stack<char>st;
        int ans=0;
        for(auto &ch:dirs){
            if(st.empty()){
                st.push(ch);
            }else{
                char tp=st.top();
                if(tp=='L'){
                    st.push(ch);
                }
                else if(tp=='S'){
                    if(ch=='R'){
                        st.push(ch);
                    }
                    if(ch=='L')ans++;
                }
                else if(tp=='R'){
                    if(ch=='R')st.push(ch);
                    else if(ch=='L'){
                        bool o=true;
                        while(!st.empty() && st.top()=='R'){
                            if(o){
                                ans+=2;
                                st.pop();
                                o=!o;
                            }else{
                                ans++;
                                st.pop();
                            }
                        }
                        st.push('S');
                    }
                    else if(ch=='S'){
                        while(!st.empty() && st.top()=='R'){
                            ans++;
                            st.pop();
                        }
                        st.push('S');
                    }
                }
                
            }
        }
        return ans;
    }
};