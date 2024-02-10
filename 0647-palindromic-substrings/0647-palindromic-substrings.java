class Solution {
    public boolean check(String str){
        StringBuilder sb=new StringBuilder(str);
        sb.reverse();
        String revstr=sb.toString();
        return str.equals(revstr);
    }
    public int countSubstrings(String s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                String str=s.substring(i,j);
                // System.out.println(str);
                if(check(str))ans++;
            }
        }
        return ans;
    }
}