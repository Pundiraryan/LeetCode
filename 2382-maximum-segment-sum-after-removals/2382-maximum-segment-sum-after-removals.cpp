class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& queries) {
        int q=queries.size();
        vector<long long>res(q);
        int n=nums.size();
        long long sum=0;
        for(auto &x:nums)sum+=x;
        vector<long long>ps(n);
        ps[0]=nums[0];
        for(int i=1;i<n;i++)ps[i]=ps[i-1]+nums[i];
        multiset<pair<int,int>>imst;
        multiset<long long>smst;
        smst.insert(0);
        smst.insert(sum);
        imst.insert({0,n-1});
        for(int i=0;i<q;i++){
            int ridx=queries[i];
            auto idx=imst.lower_bound({queries[i],1e9+5});
            idx--;
            long long lss=(ridx?ps[ridx-1]:0)-(idx->first?ps[idx->first-1]:0);
            long long rss=(ps[idx->second]-ps[ridx]);
            long long tss=ps[idx->second]-(idx->first?ps[idx->first-1]:0);
            smst.erase(smst.find(tss));
            if(idx->first<=ridx-1){
                imst.insert({idx->first,ridx-1});
                smst.insert(lss);
            }
            if(idx->second>=ridx+1){
                imst.insert({ridx+1,idx->second});
                smst.insert(rss);
            }
            imst.erase(idx);
            res[i]=*smst.rbegin();
            
        }
        return res;
    }
};