class Solution {
    public int findJudge(int n, int[][] trust) {
        int t=trust.length;
        if(t==0 && n==1)return 1;
        if(t==0)return -1;
        int []tc=new  int[n+1];
        int []tic=new int[n+1];
        for(int i=0;i<=n;i++){
            tc[i]=0;tic[i]=0;
        }
        for(int i=0;i<t;i++){
                tc[trust[i][1]]++;
                tic[trust[i][0]]++;
        }
        for(int i=0;i<=n;i++){
            if(tc[i]==(n-1) && tic[i]==0)return i;
        }
        return -1;
    }
}