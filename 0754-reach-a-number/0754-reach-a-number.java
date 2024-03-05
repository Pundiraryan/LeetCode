class Solution {
    public int reachNumber(int target) {
        int ans=0;
        int v=0;
        target=Math.abs(target);
        while(ans<target || (ans-target)%2==1){
            ans+=++v;
        }
        return v;
    }
}