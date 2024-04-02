class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        int n=nums.size(),ans=0;
        unordered_set<string> st; 
        for (int i=0; i<n; i++) {
            int cnt=0;
            string curr; 
            for (int j=i; j<n; j++) {
                curr.push_back(nums[j]); 
                if (nums[j] % p == 0)  cnt++;
                if (cnt <= k)st.insert(curr);
            }
        }
        return (int)st.size();
    }
};