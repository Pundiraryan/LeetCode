class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;
        int n=classes.size();
        for(int i=0;i<n;i++){
            double ov=((double)classes[i][0]/(double)classes[i][1]);
            double cv=(double)(classes[i][0]+1)/(double)(classes[i][1]+1);
            long double ch=cv-ov;
            pq.push({ch,{classes[i][0],classes[i][1]}});
        }
        double ans=0;
        for(int i=0;i<extraStudents;i++){
            auto curr= pq.top();
            pq.pop();
            int pass=curr.second.first;
            int total=curr.second.second;
            pass++;
            total++;
            long double growth=(double)(pass+1)/(total+1) - (double)(pass)/(total);
            pq.push({growth,{pass,total}});
        }
        while(!pq.empty()){
            ans+=(double)(pq.top().second.first)/(double)(pq.top().second.second);
            pq.pop();
        }
        return (double)ans/(double)(n);
    }
};