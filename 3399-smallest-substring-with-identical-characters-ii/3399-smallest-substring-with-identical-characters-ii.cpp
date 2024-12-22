class Solution {
public:
    int minLength(string s, int numOps) {
        int n=s.size();
        int ans=n;
        int l=1,r=n;
        auto check=[&](int mid)->bool{
           int cs1=1,cs2=1;
            int or1=0,or2=1;
            int pc1=s[0]-'0';
            int pc2=1-pc1;
            for(int i=1;i<n;i++)
            {
                int cc=s[i]-'0';
                if(cc==pc1)cs1++;
                else cs1=1;
                if(cs1>mid)
                {
                    cs1=1;
                    or1++;
                    if(i+1<n)
                    {
                        if(s[i+1]==s[i] || mid==1)pc1=1-cc;
                        else pc1=cc;
                    }
                }
                else pc1=cc;
            }
            for(int i=1;i<n;i++)
            {
                int cc=s[i]-'0';
                if(cc==pc2)cs2++;
                else cs2=1;
                if(cs2>mid)
                {
                    cs2=1;
                    or2++;
                    if(i+1<n)
                    {
                        if(s[i+1]==s[i] || mid==1)pc2=1-cc;
                        else pc2=cc;
                    }
                }
                else pc2=cc;
            } 
            return (or1<=numOps) || (or2<=numOps);
        };
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};