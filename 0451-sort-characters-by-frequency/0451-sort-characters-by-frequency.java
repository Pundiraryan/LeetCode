class Solution {
    public String frequencySort(String s) {
        int n = s.length();
        PriorityQueue<Map.Entry<Character, Integer>> pq = new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());
        Map<Character, Integer> frequencyMap = new HashMap<>();

        for (char x : s.toCharArray()) {
            frequencyMap.put(x, frequencyMap.getOrDefault(x, 0) + 1);
        }

        pq.addAll(frequencyMap.entrySet());

        StringBuilder res = new StringBuilder();
        while (!pq.isEmpty()) {
            Map.Entry<Character, Integer> entry = pq.poll();
            char ch = entry.getKey();
            int freq = entry.getValue();
            for (int i = 0; i < freq; i++) {
                res.append(ch);
            }
        }

        return res.toString();
    }
}