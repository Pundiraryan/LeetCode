vector<int>segt;
#define vi vector<int>
void build(int v,int tl,int tr,vi&arr){
    if(tl==tr){
        segt[v]=arr[tl];
        return;
    }
    int tm=(tl+tr)/2;
    build(2*v,tl,tm,arr);
    build(2*v+1,tm+1,tr,arr);
    segt[v]=segt[2*v]+segt[2*v+1];
}
void update(int v,int tl,int tr,int pos,int x,vi&arr){
    if(tl==tr){
        segt[v]=x;
        return;
    }
    int tm=(tl+tr)/2;
    if(pos<=tm){
        update(2*v,tl,tm,pos,x,arr);
    }
    else update(2*v+1,tm+1,tr,pos,x,arr);
    segt[v]=segt[2*v]+segt[2*v+1];
}
int sum(int v,int tl,int tr,int l,int r,vi &arr){
    if(l>r)return 0;
    if(l==tl&&r==tr){
        return segt[v];
    }
    int tm=(tl+tr)/2;
    return sum(2*v,tl,tm,l,min(r,tm),arr)+sum(2*v+1,tm+1,tr,max(tm+1,l),r,arr);
}
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
      int n=words.size();
      vector<int>pref(n,0);
        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
      segt.resize(4*n+1);
      for(int i=0;i<n;i++){
          int l=words[i].length();
          if(st.find(words[i][0])!=st.end() && st.find(words[i][l-1])!=st.end()){
              pref[i]=1;
          }
      }
        build(1,0,n-1,pref);
        int q=queries.size();
        vector<int>ans(q);
        for(int i=0;i<q;i++){
            ans[i]=sum(1,0,n-1,queries[i][0],queries[i][1],pref);
        }
        return ans;
    }
};