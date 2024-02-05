class Solution {
    public int firstUniqChar(String s) {
        int[] fre=new int[26];
        for(int i=0;i<s.length();i++){
            int idx=s.charAt(i)-97;
            fre[idx]++;
        }
        for(int i=0;i<s.length();i++){
            int idx=s.charAt(i)-97;
            if(fre[idx]==1)return i;
        }
        return -1;
    }
}