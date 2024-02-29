class Solution {
    public int minimumTime(String s) {
          int n = s.length();
        int[] dpl = new int[n];
        int[] dpr = new int[n];

        if (s.charAt(0) == '1') {
            dpl[0] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == '1') {
                dpl[i] = Math.min(dpl[i - 1] + 2, i + 1);
            } else {
                dpl[i] = dpl[i - 1];
            }
        }
        if (s.charAt(n - 1) == '1') {
            dpr[n - 1] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (s.charAt(i) == '1') {
                dpr[i] = Math.min(dpr[i + 1] + 2, n - i);
            } else {
                dpr[i] = dpr[i + 1];
            }
        }
        int ans = Math.min(dpr[0], dpl[n - 1]);
        for (int i = 0; i < n - 1; i++) {
            ans = Math.min(ans, dpl[i] + dpr[i + 1]);
        }
        return ans;
    }
}