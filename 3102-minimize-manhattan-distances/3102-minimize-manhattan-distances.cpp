class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> V(n), V1(n);
    for (int i = 0; i < n; i++) {
        V[i] = points[i][0] + points[i][1];
        V1[i] =  points[i][0] - points[i][1];
    }
    vector<int>premax(n,-1e9);
        vector<int>premin(n,1e9);
        vector<int>suffmax(n,-1e9);
        vector<int>suffmin(n,1e9);
        premax[0]=V[0];
        premin[0]=V[0];
        suffmax[n-1]=V[n-1];
        suffmin[n-1]=V[n-1];
        for(int i=1;i<n;i++){
            premax[i]=max(premax[i-1],V[i]);
            premin[i]=min(premin[i-1],V[i]);
            suffmax[n-1-i]=max(suffmax[n-i],V[n-i-1]);
            suffmin[n-1-i]=min(suffmin[n-i],V[n-i-1]);
        }

        vector<int>premax1(n,-1e9);
        vector<int>premin1(n,1e9);
        vector<int>suffmax1(n,-1e9);
        vector<int>suffmin1(n,1e9);
        premax1[0]=V1[0];
        premin1[0]=V1[0];
        suffmax1[n-1]=V1[n-1];
        suffmin1[n-1]=V1[n-1];
        for(int i=1;i<n;i++){
            premax1[i]=max(premax1[i-1],V1[i]);
            premin1[i]=min(premin1[i-1],V1[i]);
            suffmax1[n-1-i]=max(suffmax1[n-i],V1[n-i-1]);
            suffmin1[n-1-i]=min(suffmin1[n-i],V1[n-i-1]);
        }
        int res=1e9;
        res=min(res,max(suffmax[1]-suffmin[1],suffmax1[1]-suffmin1[1]));
        for(int i=1;i<n-1;i++){
            int cmax=max(premax[i-1],suffmax[i+1]);
            int cmin=min(premin[i-1],suffmin[i+1]);
             int cmax1=max(premax1[i-1],suffmax1[i+1]);
            int cmin1=min(premin1[i-1],suffmin1[i+1]);
            res=min(res,max(cmax-cmin,cmax1-cmin1));
        }
        res=min(res,max(premax[n-2]-premin[n-2],premax1[n-2]-premin1[n-2]));
        return res;
    }
};