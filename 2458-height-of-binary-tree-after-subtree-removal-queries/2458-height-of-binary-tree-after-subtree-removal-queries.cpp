/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define ll int
class SGTree
{
    vector<ll> seg;
 
public:
    SGTree(ll n)
    {
        seg.resize(4 * n + 1);
    }
    void build(vector<ll> &v, ll low, ll high, ll idx)
    {
        if (low == high)
        {
            seg[idx] = v[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(v, low, mid, 2 * idx);
        build(v, mid + 1, high, 2 * idx + 1);
        seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
    }
    int maxi(int index, int l, int r, int start, int end)
    {
        if ((start > r) || (end < l))
        {
            return 0;
        }
        if ((start <= l) && (end >= r))
        {
            return seg[index];
        }
        int mid = (l + r) / 2;
        int lft = maxi((index * 2) , l, mid, start, end);
        int rght = maxi((index * 2) + 1, mid + 1, r, start, end);
        return max(lft, rght);
    }
};
class Solution {
public:
    int f(TreeNode*r,int cd,unordered_map<int,int>&s,unordered_map<int,int>&d,vector<int>&flat){
        if(!r)return 0;
        d[r->val]=cd;
        flat.push_back(r->val);
        int ls=f(r->left,cd+1,s,d,flat);
        int rs=f(r->right,cd+1,s,d,flat);
        return s[r->val]=1+ls+rs;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int,int>sbsize;
        unordered_map<int,int>depth;
        unordered_map<int,int>mp;
        vector<int>flat,arr;
        f(root,0,sbsize,depth,flat);
        for(int i=0;i<flat.size();i++){
            mp[flat[i]]=i;
            arr.push_back(depth[flat[i]]);
        }
        int n=arr.size();
        SGTree st(n);
        st.build(arr,0,n-1,1);
        int q=queries.size();
        vector<int>ans(q);
        for(int i=0;i<queries.size();i++){
            int remove=queries[i];
            int fv=st.maxi(1,0,n-1,0,mp[remove]-1);
            int sv=st.maxi(1,0,n-1,mp[remove]+sbsize[remove],n-1);
            ans[i]=max(fv,sv);
        }
        return ans;
    }
};