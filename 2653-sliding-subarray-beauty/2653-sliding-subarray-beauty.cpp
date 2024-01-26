#define maxn 101
class Solution {
public:
    int tree[4*maxn]={0};
 void update (int ind, int val, int l, int r, int i) {
        if (l == r) {
            tree[i] += val;
            return;
        }

        int m = (l+r)/2;
        if (m >= ind) update (ind, val, l, m, i*2+1);
        else update (ind, val, m+1, r, i*2+2);

        tree[i] = tree[i*2+1] + tree[i*2+2];
    }

    int query (int x, int l, int r, int i) {
        if (l == r) {
            if (tree[i] >= x) return l;
            return 101;
        }

        int m = (l+r)/2;
        int lft = i*2+1, rgt = i*2+2;

        if (tree[lft] >= x) return query (x, l, m, lft);
        return query (x - tree[lft], m+1, r, rgt);
    }
 vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<k-1;i++){
            update(nums[i]+50,1,0,100,0);
        }
        for(int j=k-1;j<n;j++){
            update(nums[j]+50,1,0,100,0);
            int val=query(x,0,100,0);
            val-=50;
            if(val>=0)ans.push_back(0);
            else ans.push_back(val);
             update(nums[j-k+1]+50,-1,0,100,0);
        }
        return ans;
    }
};