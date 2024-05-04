class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int n=people.length;
        int i=0,j=n-1;
        int ans=0;
        while(i<=j){
            int val=people[i]+people[j];
            if(val>limit){
                j--;
            }else{
                i++;
                j--;
            }
            ans++;
        }
        return ans;
    }
}