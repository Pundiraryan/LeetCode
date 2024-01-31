class Solution {
    int f(int i,int j,int n,int x,ArrayList<Integer>nums,int[][] dp){
        if(i>j || i>=n ||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int case1=nums.get(i+1)-nums.get(i)+f(i+2,j,n,x,nums,dp);
        int case2= nums.get(j)-nums.get(j-1)+f(i,j-2,n,x,nums,dp);
        int case3=x+f(i+1,j-1,n,x,nums,dp);
        return dp[i][j]=Math.min(case1,Math.min(case2,case3));
    }
    public int minOperations(String s1, String s2, int x) {
        int[][] dp=new int[501][501];
        for(int[] row:dp){
            Arrays.fill(row,-1);
        }
         ArrayList<Integer>nums=new ArrayList<>();
        int n=s1.length();
        for(int i=0;i<n;i++){
            if(s1.charAt(i)!=s2.charAt(i)){
                nums.add(i);
            }
        }
        if(nums.size()%2==1)return -1;
         
        return f(0,nums.size()-1,nums.size(),x,nums,dp);
    }
}