class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        for(int i=30;i>=0;i--){
            int bit1=(left>>i)&1;
            int bit2=(right>>i)&1;
            if(bit1==0 && bit2==0)continue;
            if((bit1==1 && bit2==0) || (bit2==1 && bit1==0)){
                break;
            }
            ans|=(1<<i);

        }
        return ans;
    }
}