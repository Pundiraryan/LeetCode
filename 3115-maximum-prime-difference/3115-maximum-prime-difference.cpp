class Solution {
public:
    bool isPrime(int n)
{
    if (n <= 1)return false;
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(isPrime(nums[i]))v.push_back(i);
        }
        return v.back()-v.front();
    }
};