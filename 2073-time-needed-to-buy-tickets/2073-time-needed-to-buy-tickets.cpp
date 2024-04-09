class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=1;
        int ti=k;
        while(tickets[ti]>0){
            if(ti==0){
                int val=tickets[0];
                tickets.erase(tickets.begin());
                if(val>1){
                    tickets.push_back(val-1);
                    ans++;
                ti=tickets.size()-1;
                }else{
                    break;
                }
                
            }else{
                int val=tickets[0];
                tickets.erase(tickets.begin());
                if(val>1){
                    tickets.push_back(val-1);
                }
                ans++;
                ti--;
            }
        }
        return ans;
    }
};