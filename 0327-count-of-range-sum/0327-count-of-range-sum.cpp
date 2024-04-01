
#include <ext/pb_ds/assoc_container.hpp>   
#include <ext/pb_ds/tree_policy.hpp>    
using namespace __gnu_pbds;
typedef tree<long, null_type, less_equal<long>, rb_tree_tag,  
            tree_order_statistics_node_update>  
    ordered_set;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int ans = 0;
        long long sum = 0;
        ordered_set st;
        st.insert(0);
        for (auto &x:nums) {
            sum += x;
            int a = st.order_of_key(sum - upper);
            int b = st.order_of_key(sum - lower + 1);
            ans += max(0, b - a);
            st.insert(sum);
        }
        
        return ans;
    }
};