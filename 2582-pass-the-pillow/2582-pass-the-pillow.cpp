class Solution {
public:
    int passThePillow(int n, int time) {
        int d=-1,cp=1;
        for(int i=0;i<time;i++){
            if(cp==1) d=1;
            else if(cp==n) d=-1;
            cp+=d;
        }
        return cp;
    }
};