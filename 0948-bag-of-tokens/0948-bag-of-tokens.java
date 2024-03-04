class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);
        int n=tokens.length;
        int ans=0;
        int si=0,sd=n-1;
        int sc=0,cp=power;
        while(si<=sd){
            ans=Math.max(ans,sc);
            if(cp>=tokens[si]){
                cp-=tokens[si];
                sc++;
                si++;
            }
            else if(sc>=1){
                cp+=tokens[sd];
                sc--;
                sd--;
            }else{
                break;
            }
        }
        return Math.max(ans,sc);
    }
}