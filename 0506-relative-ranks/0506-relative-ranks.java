class Solution {
    public String[] findRelativeRanks(int[] score) {
        int n=score.length;
        String[] ans=new String[n];
        HashMap<Integer,Integer>fre=new HashMap<>();
        for(int i=0;i<n;i++){
            fre.put(score[i],i);
        }
        Arrays.sort(score);
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                ans[fre.get(score[i])]="Gold Medal";
            }else if(i==n-2){
                ans[fre.get(score[i])]="Silver Medal";
            }else if(i==n-3){
                ans[fre.get(score[i])]="Bronze Medal";
            }else{
                ans[fre.get(score[i])]=Integer.toString(n-i);
            }
        }
        return ans;
    }
}