class Solution {
    public boolean isp(String str){
        StringBuilder st=new StringBuilder(str);
        st.reverse();
        String revstr=st.toString();
        if(str.equals(revstr))return true;
        return false;
    }
    public String firstPalindrome(String[] words) {
        int n=words.length;
        for(int i=0;i<n;i++){
            if(isp(words[i]))return words[i];
        }
        return "";
    }
}