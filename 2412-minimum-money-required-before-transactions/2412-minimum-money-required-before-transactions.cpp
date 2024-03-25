bool cmp1(vector<int> &a, vector<int> &b) {
        if(a[1] == b[1])
            return a[0] > b[0];
        return a[1] < b[1];
    }
    
bool cmp2(vector<int> &a, vector<int> &b) {
        return a[0] > b[0];
    }
class Solution {
    bool possible(vector<vector<int>>&ltr, vector<vector<int>>&ptr, long long ans) {
        for(int i = 0; i <ltr.size(); i++) {
            if(ans >=ltr[i][0]) 
                ans = (ans -ltr[i][0] +ltr[i][1]);
            else 
                return false;
        }
        
        for(int i = 0; i <ptr.size(); i++) {
            if(ans >=ptr[i][0]) 
                ans = (ans -ptr[i][0] +ptr[i][1]);
            else 
                return false;
        }
        
        return true;
    }

public:
    long long minimumMoney(vector<vector<int>>& tr) {
        vector<vector<int>>ltr,ptr;
        for(int i = 0; i < tr.size(); i++) {
            if(tr[i][1] >= tr[i][0])
            ptr.push_back({tr[i][0], tr[i][1]});
            else 
            ltr.push_back({tr[i][0], tr[i][1]});
        }
        
        sort(ltr.begin(),ltr.end(), cmp1);
        sort(ptr.begin(),ptr.end(), cmp2);
        
        long long ans = 0;
        long long low = 0, high = 1e16;
        while(low <= high) {
            long long mid = (low + high) / 2;
            if(possible(ltr,ptr, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};