class Solution {
    public int minimumSeconds(List<Integer> nums) {
        int n=nums.size();
        Map<Integer,List<Integer>>fre=new HashMap<>();
        for(int i=0;i<n;i++){
            int num = nums.get(i);
            if (!fre.containsKey(num)) {
                fre.put(num, new ArrayList<>());
            }
            fre.get(num).add(i);
        }
        int ans=n;
        for(Map.Entry<Integer,List<Integer>>entry:fre.entrySet()){
            int x=entry.getKey();
            int cans=0;
            List<Integer>positions=entry.getValue();
            for (int i = 0; i < positions.size() - 1; i++) {
                int diff = (positions.get(i + 1) - positions.get(i)) / 2;
                cans = Math.max(cans, diff);
            }

            cans = Math.max(cans, (positions.get(0) + (n - 1 -                         positions.get(positions.size() - 1) + 1)) / 2);
            ans = Math.min(ans, cans);
        }
        return ans;
        
    }
}