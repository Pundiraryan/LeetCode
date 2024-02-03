class Solution {
    public boolean check(String s,int num){
        if(s.length()==0 && num==0)return true;
        if(s.length()==0)return false;
        if(s.length()==1 && Integer.parseInt(s)!=num)return false;
        if(Integer.parseInt(s)==num)return true;
        boolean ans=false;
        for(int i=1;i<s.length();i++){
            ans =  check(s.substring(i), num - Integer.parseInt(s.substring(0,i)));
            if(ans)return true;
        }
        return false;
    }
    public int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(check(String.valueOf(i*i),i)){
                ans+=(i*i);
            }
        }
        return ans;
    }
}