class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0;
        while(numBottles>0){
            if(numBottles<numExchange){
                ans+=numBottles;
                break;
            }
            numBottles-=numExchange;
            ans+=numExchange;
            numBottles++;
            numExchange++;
        }
        return ans;
    }
};