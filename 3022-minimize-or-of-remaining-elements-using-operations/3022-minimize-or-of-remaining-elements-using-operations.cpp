
class Solution {
public:
    int findops(int canbits,vector<int>&taken,vector<int>&nums){
        int ops=0;
        int i=0;
        while(i<nums.size()){
            if(!taken[i]){
                i++;
                continue;
            }
            int j=i;
            int alland=nums[j];
            while(i<nums.size() && taken[i]&& (canbits&alland)!=0){
                alland&=nums[i];
                i++;
            }
            if((alland&canbits)==0)ops+=(i-j-1);
            else ops+=(i-j);
        }
        return ops;
    }
    int minOrAfterOperations(vector<int>& nums, int k) {
        int ans=0;
        int canbits=0;
        for(int bit=29;bit>=0;bit--){
            int newcanbits=canbits|(1<<bit);
            vector<int>taken(nums.size(),false);
            for(int i=0;i<nums.size();i++){
                if(newcanbits&nums[i]){
                    taken[i]=true;
                }
            }
            if(findops(newcanbits,taken,nums)<=k){
                canbits=newcanbits;
            }else{
                ans|=(1<<bit);
            }
        }
        return ans;
    }
};