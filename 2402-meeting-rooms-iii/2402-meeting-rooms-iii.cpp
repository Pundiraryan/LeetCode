class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<long long ,long long>,vector<pair<long long ,long long >>,greater<pair<long long ,long long>>>pq;
        vector<long long>vstd(n,0); //indicates empty room
        vector<long long>cnt(n,0);
        // ans is index of larges cnt[i] 
        for(auto x:meetings){
            while(!pq.empty() && x[0]>=pq.top().first){
                // valid room but may not be smallest index
                auto curr=pq.top();
                pq.pop();
                vstd[curr.second]=0;
            }
            bool found=false;
            for(int i=0;i<n;i++){
                if(!vstd[i]){
                    vstd[i]=1;
                    pq.push({x[1],i});
                    cnt[i]++;
                    found=true;
                    break;
                    
                }
            }
            if(!found){

					auto m = pq.top();
					pq.pop();
					pq.push({x[1]+m.first-x[0], m.second});
					cnt[m.second]++;
					vstd[m.second]=1;
				}
        }
        long long ans=0;
        long long cmax=-1;
        for(long long i=0;i<n;i++){
            if(cnt[i]>cmax){
                cmax=cnt[i];
                ans=i;
            }
        }
        return ans;
        
    }
};