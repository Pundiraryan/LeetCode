class Solution {
public:
    int halveArray(vector<int>& nums) {
        int ans=0;
        double sum=0;
        priority_queue<double>pq;
        for(auto &x:nums){
            pq.push(x);
            sum+=x;
        }
        double tar=sum/2.0;
        while(sum>tar){
            double val=pq.top();
            pq.pop();
            sum-=val/2.0;
            ans++;
            pq.push(val/2.0);
        }
        return ans;
    }
};