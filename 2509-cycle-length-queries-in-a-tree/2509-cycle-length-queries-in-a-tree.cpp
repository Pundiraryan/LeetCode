#define ll long long
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int q=queries.size();
        vector<int>ans(q);
        for(int i=0;i<q;i++){
            int a=queries[i][0];
            int b=queries[i][1];
            if(a>b)swap(a,b);
            int  moves=0;
            while(b>0 && (int)log2(a)!=(int)log2(b)){
                b/=2;moves++;
            }
            //now and b are at same level;
            while(a!=b){
                a/=2;b/=2;moves+=2;
            }
            ans[i]=moves+1;
        }
        return ans;
    }
};