class Solution {
public:
    bool isvalid(int i,int j,int r,int c){
        return (i>=0)&&(i<r)&&(j>=0)&&(j<c);
    }
    int f(int i,int j,vector<vector<int>>&img){
        int r= img.size(),c=img[0].size();
        int cnt=0,sum=0;
        for(int x=-1;x<2;x++){
            for(int y=-1;y<2;y++){
                if(isvalid(i+x,j+y,r,c)){
                    sum+=img[i+x][j+y];
                    cnt++;
                }
            }
        }
        return (sum)/cnt;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r=img.size(),c=img[0].size();
        vector<vector<int>>res(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res[i][j]=f(i,j,img);
            }
        }
        return res;
    }
};