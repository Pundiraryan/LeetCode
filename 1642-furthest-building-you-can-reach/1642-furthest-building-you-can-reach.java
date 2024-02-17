class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        int n=heights.length;
           PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder()); 
        int i;
        for(i=0;i<n-1;i++){
            if(heights[i]>=heights[i+1])continue;
            int val=heights[i+1]-heights[i];
                bricks-=(val);
                pq.offer(val); 
                if(bricks<0){
                    if(ladders<=0)return i;
                    bricks+=pq.poll();
                    ladders--;

                }
            }
        return n-1;
    }
}