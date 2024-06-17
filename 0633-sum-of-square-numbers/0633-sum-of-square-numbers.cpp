class Solution {
public:
    bool check(long long num){
        long long sv=(long long)sqrtl(num);
        return (sv*sv)==num;
    }
    bool judgeSquareSum(int c) {
        for(long long i=0;i<=(long long)(sqrtl(c));i++){
            if(check(c-i*i))return true;
        }
            return false;
    }
};