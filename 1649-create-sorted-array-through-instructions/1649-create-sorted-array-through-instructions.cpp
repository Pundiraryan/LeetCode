#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag,
tree_order_statistics_node_update>;
#define mod 1000000007
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        ordered_multiset<int>mst;
        long long ans=0,n=instructions.size();
        mst.insert(instructions[0]);
        for(int i=1;i<n;i++){
            int idx=mst.order_of_key(instructions[i]);
            int ridx=mst.size()-mst.order_of_key(instructions[i]+1);
            int cost=min(idx,ridx);
            ans=(ans+cost)%mod;
            mst.insert(instructions[i]);
        }
        return ans%mod;
    }
};