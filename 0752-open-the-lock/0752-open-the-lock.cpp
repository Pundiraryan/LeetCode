class Solution {
public:
    vector<string> f(string &str){
        vector<string>res;
        string ostr=str;
        for(int i=0;i<4;i++){
            string tmp = str;
            tmp[i] = (str[i]-'0'+1) % 10 + '0';
            res.push_back(tmp);
            tmp[i] = (str[i]-'0'-1+10)%10 + '0';
            res.push_back(tmp);
        }
        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        string lock="0000";
        queue<string>bfs;
        unordered_set<string>vstd,dead;
        for(auto &x:deadends)dead.insert(x);
        if(dead.find(lock)!=dead.end())return -1;
        vstd.insert(lock);
        bfs.push(lock);
        int ans=0;
        while(!bfs.empty()){
            int sz=bfs.size();
            while(sz--){
               string cl=bfs.front();
                bfs.pop();
                if(cl==target)return ans;
                vector<string>gen=f(cl);
                for(auto &x:gen){
                    if(vstd.find(x)!=vstd.end())continue;
                    if(dead.find(x)!=dead.end())continue;
                    vstd.insert(x);
                    bfs.push(x);
                }
            }
            ans++;
        }
        return -1;
    }
};