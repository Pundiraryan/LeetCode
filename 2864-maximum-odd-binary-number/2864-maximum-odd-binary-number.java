class Solution {
    public String maximumOddBinaryNumber(String s) {
        int c1=0,n=s.length();
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='1')c1++;
        }
        for(int i=0;i<c1-1;i++)sb.append('1');
        for(int i=0;i<n-c1;i++)sb.append('0');
        sb.append('1');
        return sb.toString();
    }
}