class Solution {
public:
    int compareVersion(string version1, string version2) {
        long long val1=0,val2=0;
        int n=version1.length(),m=version2.length();
        int i=0,j=0;
        while(i<n || j<m){
            int ni=i,nj=j;
            while(ni<n && version1[ni]!='.'){
                val1=(long long)(val1*10+version1[ni]-'0');
                ni++;
            }
            while(nj<m && version2[nj]!='.'){
                val2=(long long)(val2*10+version2[nj]-'0');
                nj++;
            }
            if(val1<val2)return -1;
            if(val1>val2)return 1;
            ni++;nj++;
            i=ni;j=nj;
            val1=0;val2=0;
            
        }
        return 0;
    }
};