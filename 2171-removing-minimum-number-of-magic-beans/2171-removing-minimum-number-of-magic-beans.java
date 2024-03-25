class Solution {
    public long minimumRemoval(int[] beans) {
        int n=beans.length;
        long ans=Long.MAX_VALUE;
        Arrays.sort(beans);
        long[] ss=new long[n];
        long[] ps=new long[n];
        ss[n-1]=beans[n-1];
        ps[0]=beans[0];
        for(int i=n-2;i>=0;i--){
            ss[i]=ss[i+1]+beans[i];
            ps[n-1-i]=ps[n-i-2]+beans[n-1-i];
        }
        int i=0;
        while(i<n){
            long val1=0;
            if(i<n-1)val1+=ss[i+1];
            long val2=(long)(n-1-i)*(beans[i]);
            long val3=0;
            if(i>0)val3+=ps[i-1];
                ans=Math.min(ans,(long)(val1-val2+val3));
            
            int j=i+1;
            while(j<n && beans[j]==beans[i])j++;
            i=j;
        }
        return ans;
    }
}