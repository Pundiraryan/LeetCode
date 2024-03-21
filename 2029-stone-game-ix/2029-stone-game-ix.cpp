class Solution {
public:
    bool f(int s,int zc,int oc,int tc,int turn){
        if(zc==0 && oc==0 && tc==0 )return 1;
        int w=turn^1;
        if(s==0){
            if(oc>0)w=f(1,zc,oc-1,tc,turn^1);
            if(w!=turn && tc>0)w=f(2,zc,oc,tc-1,turn^1);
        }
        else if(s==1){
            if(zc>0)w=f(1,zc-1,oc,tc,turn^1);
            if(w!=turn  && oc>0)w=f(2,zc,oc-1,tc,turn^1);
        }else{
            if(zc>0)w=f(2,zc-1,oc,tc,turn^1);
            if(w!=turn && tc>0)w=f(1,zc,oc,tc-1,turn^1);
        }
        return w;
    }
    bool stoneGameIX(vector<int>& stones) {
        int oc=0,zc=0,tc=0;
        for(int i=0;i<stones.size();i++){
            if(stones[i]%3==1)oc++;
            else if(stones[i]%3==2)tc++;
            else zc^=1;
        }
        return f(0,zc,oc,tc,0)==0;
    }
};