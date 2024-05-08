class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xo1=0,xo2=0;
        for(auto &x:arr1)xo1^=x;
        for(auto &x:arr2)xo2^=x;
        return xo1&xo2;
    }
};