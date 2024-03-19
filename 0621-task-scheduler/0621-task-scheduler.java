class Solution {
    public int leastInterval(char[] tasks, int n) {
        int m=tasks.length;
        int[] freq=new int[26];
        for(int i=0;i<m;i++){
            freq[tasks[i]-'A']++;
        }
        Arrays.sort(freq);
        int mf=freq[25];
        int cnt=0;
        for(int i=25;i>=0;i--){
            if(freq[i]==mf)cnt++;
        }
        return Math.max(m,cnt+(n+1)*(mf-1));
        
    }
}