class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int cnt = 0;
        if (goal == 0) {
            int i = 0;
            while (i < nums.length) {
                int j = i;
                while (j < nums.length && nums[j] == 0) {
                    j++;
                }
                cnt += ((j - i) * (j - i + 1)) / 2;
                if (j == i)
                    i++;
                else
                    i = j;
            }
            return cnt;
        }

        HashMap<Integer, Integer> fre = new HashMap<>();
        fre.put(0, 1);
        int ans = 0, ps = 0;
        for (int val : nums) {
            ps += val;
            ans += fre.getOrDefault(ps - goal, 0);
            fre.put(ps, fre.getOrDefault(ps, 0) + 1);
        }
        return ans;
    }
}