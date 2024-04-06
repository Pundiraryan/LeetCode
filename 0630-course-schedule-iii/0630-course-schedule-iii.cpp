bool cmp(vector<int>&a,vector<int>&b){
    if(a[1]==b[1])return a[0]<b[0];
    return a[1]<b[1];
}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        int ans=0,cd=0;
        priority_queue<int>pq;
        for(auto &x:courses){
           pq.push(x[0]);
           cd+=x[0];
           if(cd>x[1]){
            int val=pq.top();
            pq.pop();
            cd-=val;
           }
        }
        return pq.size();
    }
};