class Solution {
     public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> ans = new ArrayList<>();
        String st = String.valueOf(low);
        String end = String.valueOf(high);
        for (int i = st.length(); i <= end.length(); i++) {
            for (int j = 1; j <= 9; j++) {
                StringBuilder curr = new StringBuilder();
                for (int k = j; k < Math.min(10, j + i); k++) {
                    curr.append(k);
                }
                if (curr.length() != i) {
                    continue;
                }
                int num = Integer.parseInt(curr.toString());
                if (num >= low && num <= high) {
                    ans.add(num);
                }
            }
        }
        ans.sort(null);
        return ans;
    }
}