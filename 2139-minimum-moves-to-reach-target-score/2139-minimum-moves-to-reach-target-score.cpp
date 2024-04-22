class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ov=target;
        int ans=0;
        while(ov!=1){
            if(maxDoubles==0){
                return ans+ov-1;
            }
            if(maxDoubles>0 && ov%2==0){
                maxDoubles--;
                ov/=2;
                ans++;
            }
            else if(maxDoubles>0 && ov%2==1){
                ans++;
                ov--;
            }
        }
        return ans;
    }
};