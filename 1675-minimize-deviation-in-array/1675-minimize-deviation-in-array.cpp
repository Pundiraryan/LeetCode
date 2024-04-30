class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        multiset<int>mst;
        for(auto &x:nums){
            if(x%2==1)mst.insert(x*2);
            else mst.insert(x);
        }
        int ans=*mst.rbegin()-*mst.begin();
        while(true){
            int mnv=*mst.begin(),mxv=*mst.rbegin();
            if(mxv%2==1)break;
            mst.erase(mst.find(mxv));
            mst.insert(mxv/2);
            ans=min(ans,*mst.rbegin()-*mst.begin());
        }
        return ans;
    }
};