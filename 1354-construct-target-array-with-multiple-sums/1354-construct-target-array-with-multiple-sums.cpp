class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long>pq;
        long long sum=0;
        for(auto &x:target){
            pq.push(x);sum+=x;
        }
        while(!pq.empty()){
            long long mxval=pq.top();
            pq.pop();
            long long rs=sum-mxval;
            if(mxval==1 || rs==1)return true;
            if(rs<=0 || mxval<rs)return false;
            long long nv=mxval%rs;
            if(nv<=0)return false;
            pq.push(nv);
            sum=rs+nv;
        }
        return true; 
    }
};