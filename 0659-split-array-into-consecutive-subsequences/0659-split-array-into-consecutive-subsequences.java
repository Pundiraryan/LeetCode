class Solution {
    public boolean isPossible(int[] nums) {
        int n=nums.length;
        HashMap<Integer,Integer>fre=new HashMap<>();
        for(int i=0;i<n;i++){
            fre.put(nums[i],fre.getOrDefault(nums[i],0)+1);
        }
        HashMap<Integer,Integer>req=new HashMap<>();
        for(int i=0;i<n;i++){
            if(fre.get(nums[i])<=0)continue;
            else if(req.getOrDefault(nums[i],0)>0){
                fre.put(nums[i],fre.getOrDefault(nums[i],0)-1);
                req.put(nums[i],req.getOrDefault(nums[i],0)-1);
                req.put(nums[i]+1,req.getOrDefault(nums[i]+1,0)+1);
            }
            else if(fre.getOrDefault(nums[i],0)>0 && fre.getOrDefault(nums[i]+1,0)>0 && fre.getOrDefault(nums[i]+2,0)>0){
                 fre.put(nums[i],fre.getOrDefault(nums[i],0)-1);
                 fre.put(nums[i]+1,fre.getOrDefault(nums[i]+1,0)-1);
                 fre.put(nums[i]+2,fre.getOrDefault(nums[i]+2,0)-1);
                 req.put(nums[i]+3,req.getOrDefault(nums[i]+3,0)+1);
            }
            else{
                return false;
            }
        }
            
        return true;
    }
}