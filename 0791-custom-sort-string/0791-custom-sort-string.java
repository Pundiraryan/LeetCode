class Solution {
    public String customSortString(String order, String s) {
        int[] freq=new int[26];
        for(int i=0;i<s.length();i++){
            freq[s.charAt(i)-'a']++;
        }
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<order.length();i++){
            if(freq[order.charAt(i)-'a']>0){
                while(freq[order.charAt(i)-'a']>0){
                    sb.append(order.charAt(i));
                    freq[order.charAt(i)-'a']--;
                }
            }
        }
        for(char ch='a';ch<='z';ch++){
            if(freq[ch-'a']>0){
                while(freq[ch-'a']>0){
                    sb.append(ch);
                    freq[ch-'a']--;
                }
            }
        }
        return sb.toString();
    }
}