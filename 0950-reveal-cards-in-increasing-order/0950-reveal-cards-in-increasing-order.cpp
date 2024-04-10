class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>ans(n,-1);
        sort(deck.begin(),deck.end());
        queue<int>q;
        for(int i=0;i<n;i++)q.push(i);
        vector<int>ro(n);
        for(int i=0;i<n;i++){
            ro[i]=q.front();
            q.pop();
            q.push(q.front());
            q.pop();
        }
        for(int i=0;i<n;i++){
            ans[ro[i]]=deck[i];
        }
        return ans;
    }
};