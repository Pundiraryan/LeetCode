class Solution {
    public int minStoneSum(int[] piles, int k) {
        int stones = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int x : piles) {
            stones += x;
            pq.offer(x);
        }
        while (k > 0) {
            int top = pq.poll();
            stones -= (top / 2);
            pq.offer(top - (top / 2));
            k--;
        }
        
        return stones;
    }
}