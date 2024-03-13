class Solution {
    public int pivotInteger(int n) {
        if(n==1)return 1;
        for(int x=2;x<=n;x++){
            if(2*x*x==n*(n+1))return x;
        }
        return -1;
    }
}