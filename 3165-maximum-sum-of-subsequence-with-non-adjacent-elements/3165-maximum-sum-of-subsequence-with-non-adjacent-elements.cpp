#define mod 1000000007
#define ll long long int

class Solution {
public:
    array<array<int, 2>, 2> tree[200000];

    void build(int in, int l, int r, vector<int>&nums){
        if(l==r){
            tree[in][0][0]=tree[in][0][1]=tree[in][1][0]=0;
            tree[in][1][1]=nums[l];
        }
        else{
            int m = l+((r-l)>>1);
            build(in<<1, l, m, nums);
            build((in<<1) + 1, m+1, r, nums);

            tree[in][0][0]=max(tree[in<<1][0][0]+tree[(in<<1) + 1][0][0], max(tree[in<<1][0][1]+tree[(in<<1) + 1][0][0], tree[in<<1][0][0]+tree[(in<<1) + 1][1][0]));
            tree[in][0][1]=max(tree[in<<1][0][0]+tree[(in<<1) + 1][0][1], max(tree[in<<1][0][1]+tree[(in<<1) + 1][0][1], tree[in<<1][0][0]+tree[(in<<1) + 1][1][1]));
            tree[in][1][0]=max(tree[in<<1][1][0]+tree[(in<<1) + 1][0][0], max(tree[in<<1][1][0]+tree[(in<<1) + 1][1][0], tree[in<<1][1][1]+tree[(in<<1) + 1][0][0]));
            tree[in][1][1]=max(tree[in<<1][1][0]+tree[(in<<1) + 1][0][1], max(tree[in<<1][1][0]+tree[(in<<1) + 1][1][1], tree[in<<1][1][1]+tree[(in<<1) + 1][0][1]));
       }
    }

    void update(int in, int l, int r, int pos, int x, vector<int>&nums){
        if(l==r){
            nums[pos]=x;
            tree[in][1][1]=x;
        }
        else{
            int m=l+((r-l)>>1);
            if(pos>=l && pos<=m)update(in<<1, l, m, pos, x, nums);
            else update((in<<1) + 1, m+1, r, pos, x, nums);

            tree[in][0][0]=max(tree[in<<1][0][0]+tree[(in<<1) + 1][0][0], max(tree[in<<1][0][1]+tree[(in<<1) + 1][0][0], tree[in<<1][0][0]+tree[(in<<1) + 1][1][0]));
            tree[in][0][1]=max(tree[in<<1][0][0]+tree[(in<<1) + 1][0][1], max(tree[in<<1][0][1]+tree[(in<<1) + 1][0][1], tree[in<<1][0][0]+tree[(in<<1) + 1][1][1]));
            tree[in][1][0]=max(tree[in<<1][1][0]+tree[(in<<1) + 1][0][0], max(tree[in<<1][1][0]+tree[(in<<1) + 1][1][0], tree[in<<1][1][1]+tree[(in<<1) + 1][0][0]));
            tree[in][1][1]=max(tree[in<<1][1][0]+tree[(in<<1) + 1][0][1], max(tree[in<<1][1][0]+tree[(in<<1) + 1][1][1], tree[in<<1][1][1]+tree[(in<<1) + 1][0][1]));

        }
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=0;
        build(1, 0, nums.size()-1, nums);
        for(auto q:queries){
            update(1, 0, nums.size()-1, q[0], q[1], nums);
            ans = (ans + max(tree[1][0][0], max(tree[1][0][1], max(tree[1][1][0], tree[1][1][1])))%mod)%mod;
        }
        return ans;
    }
};