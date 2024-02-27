class Solution {
    public boolean valid(String s){
        int n=s.length();
        for(int i=0;i<n-1;i++){
            if(s.charAt(i)!=s.charAt(i+1))return false;
        }
        return true;
    }
    public int maximumLength(String s) {
        int n=s.length();
        int ans=-1;
        Map<String,Integer>fre=new HashMap<String,Integer>();
        for(int i=0;i<n;i++){
            StringBuilder sb=new StringBuilder();
            for(int j=i;j<n;j++){
                sb.append(s.charAt(j));
                if(valid(sb.toString())){
                    String val=sb.toString();
                    fre.put(val,fre.getOrDefault(val,0)+1);
                    if(fre.getOrDefault(val,0)>=3){
                        ans=Math.max(ans,val.length());
                    }
                }
            }
        }
        return ans;
    }
}