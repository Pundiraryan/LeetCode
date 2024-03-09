class Solution {
    public boolean sumGame(String num) {
        int n=num.length();
        int q1=0,q2=0,sum1=0,sum2=0;
        for(int i=0;i<n/2;i++){
            if(num.charAt(i)=='?')q1++;
            else sum1+=num.charAt(i)-'0';
        }
        for(int i=n/2;i<n;i++){
            if(num.charAt(i)=='?')q2++;
            else sum2+=num.charAt(i)-'0';
        }
        if(q1==0 && q2==0){
            return sum1!=sum2;
        }
        if((q1+q2)%2==1)return true;
        int qmin=Math.min(q1,q2);
        q1-=qmin;q2-=qmin;
        return sum1+9*(q1/2)!=sum2+9*(q2/2);
        
    }
}