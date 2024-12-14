class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        map<int,int>fre;
        int j=0,i=0;
        while(j<n){
            fre[nums[j]]++;
            while(fre.rbegin()->first-fre.begin()->first >2){
                fre[nums[i]]--;
                if(fre[nums[i]]==0){
                 fre.erase(nums[i]);   
                }
                
                i++;
            }
            ans+=(long long)(j-i+1);
            j++;
        }
        return ans;
    }
};