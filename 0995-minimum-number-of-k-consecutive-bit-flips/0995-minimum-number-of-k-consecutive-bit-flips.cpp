class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        queue<int>q;
        for(int i=0;i<n;i++){
              if(nums[i]==0){
                  if(q.empty() || q.size()%2==0){
                      ans++;
                      q.push(i+k-1);
                  }
              }else{
                  if(q.size()%2==1){
                      ans++;
                      q.push(i+k-1);
                  }
              }
            if(!q.empty() && q.front()==i)q.pop();
        }
        if(q.empty())return ans;
        return -1;
    }
};