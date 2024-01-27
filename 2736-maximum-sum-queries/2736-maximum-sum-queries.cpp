class Solution {
public:
    
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
    
    bool static cmp2(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] > b[0];
    }
    
    void update(int nl, int nr, int tidx, int idx, int val, vector<int> &tree) {
        if(nl == nr) {
            tree[tidx] = max(val, tree[tidx]);
            return; 
        }
        
        int mid = (nl+nr)/2; 
        if(idx <= mid) {
            update(nl, mid, 2*tidx+1, idx, val, tree);
        } else {
            update(mid+1, nr, 2*tidx+2, idx, val, tree);
        }
        
        tree[tidx] = max(tree[2*tidx+1], tree[2*tidx+2]);
    }
    
    int query(int nl, int nr, int tidx, int l, int r, vector<int> &tree) {
        if(nl > r or nr < l) return INT_MIN;
        if(nl >= l and nr <= r) return tree[tidx];
        
        int mid = (nl+nr)/2;
        int left = query(nl, mid, 2*tidx+1, l, r, tree);
        int right = query(mid+1, nr, 2*tidx+2, l, r, tree);
        
        return max(left, right); 
    }
    
    
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<int> temp; 
        vector<pair<int, int>> v;
        int n = nums1.size();
        int m = queries.size();
        
        unordered_map<int, int> mp; 
        
        for(int i = 0; i < n; i++) {
            temp.push_back(nums2[i]);
            v.push_back({nums1[i], nums2[i]});
        }
        for(auto &q: queries) {
            int y = q[1];
            temp.push_back(y);
        }
        sort(temp.begin(), temp.end()); 
        sort(v.begin(), v.end(), cmp); 
        
        int newVal = 0; 
        
        for(int i = 0; i < temp.size(); i++) {
            if(mp.find(temp[i]) != mp.end()) continue; 
            mp[temp[i]] = newVal++; 
        }
        
        int N = newVal+1;
        vector<int> tree(4*N+1, -1);
        for(int i = 0; i < m; i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), cmp2);
        
        vector<int> ans(m);

        int j = 0; 
        for(int i = 0; i < m; i++){
            auto q = queries[i]; 
            int idx = q[2];
            int x = q[0];
            int y = q[1];
            
            
            while(j < n and v[j].first >= x) {
                int X = v[j].first;
                int Y = v[j].second; 
                int val = X+Y; 
                int index = mp[Y]; 
                update(0, N-1, 0, index, val, tree); 
                j++; 
            }
            
            
            int maxi = query(0, N-1, 0, mp[y], N, tree);
            ans[idx] = maxi; 
        }
        
        
        return ans;
    }
};