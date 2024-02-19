class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n<=0)return false;
        int cnt=0;
        for(int i=30;i>=0;i--){
            if(((n>>i)&1 )==1)cnt++;
        }
        return cnt==1;
    }
}