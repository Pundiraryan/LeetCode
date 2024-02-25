class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.length();
        if(k==0)return 0;
        vector<int>prefa(n,0),prefb(n,0),prefc(n,0);
        if(s[0]=='a')prefa[0]=1;
        if(s[0]=='b')prefb[0]=1;
        if(s[0]=='c')prefc[0]=1;
        for(int i=1;i<n;i++){
           prefa[i]=prefa[i-1]+(s[i]=='a');
            prefb[i]=prefb[i-1]+(s[i]=='b');
            prefc[i]=prefc[i-1]+(s[i]=='c');
        }
        vector<int>suffa(n,0),suffb(n,0),suffc(n,0);
        if(s[n-1]=='a')suffa[n-1]=1;
        if(s[n-1]=='b')suffb[n-1]=1;
        if(s[n-1]=='c')suffc[n-1]=1;
        for(int i=n-2;i>=0;i--){
           suffa[i]=suffa[i+1]+(s[i]=='a');
            suffb[i]=suffb[i+1]+(s[i]=='b');
            suffc[i]=suffc[i+1]+(s[i]=='c');
        }
        if(*max_element(prefa.begin(),prefa.end())<k || *max_element(prefb.begin(),prefb.end())<k || *max_element(prefc.begin(),prefc.end())<k)return -1;
        int ans=1e9;
        int ac=0,bc=0,cc=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a')ac++;
            if(s[i]=='b')bc++;
            if(s[i]=='c')cc++;
            int areq=k-ac;
            int breq=k-bc;
            int creq=k-cc;
            auto idx1=lower_bound(prefa.begin(),prefa.end(),areq);
            auto idx2=lower_bound(prefb.begin(),prefb.end(),breq);
            auto idx3=lower_bound(prefc.begin(),prefc.end(),creq);
            int pos1=idx1-prefa.begin();
            int pos2=idx2-prefb.begin();
            int pos3=idx3-prefc.begin();
            int maxpos=max({pos1,pos2,pos3});
            if(areq<=0  && breq<=0 && creq<=0)maxpos=-1;
            ans=min(ans,n-i+maxpos+1);
        }
        ac=0,bc=0,cc=0;
        reverse(suffa.begin(),suffa.end());
        reverse(suffb.begin(),suffb.end());
        reverse(suffc.begin(),suffc.end());
        for(int i=0;i<n;i++){
            if(s[i]=='a')ac++;
            if(s[i]=='b')bc++;
            if(s[i]=='c')cc++;
            int areq=k-ac;
            int breq=k-bc;
            int creq=k-cc;
            auto idx1=lower_bound(suffa.begin(),suffa.end(),areq);
            auto idx2=lower_bound(suffb.begin(),suffb.end(),breq);
            auto idx3=lower_bound(suffc.begin(),suffc.end(),creq);
            int pos1=idx1-suffa.begin();
            int pos2=idx2-suffb.begin();
            int pos3=idx3-suffc.begin();
            int maxpos=max({pos1,pos2,pos3});
            if(areq<=0  && breq<=0 && creq<=0)maxpos=-1;
            ans=min(ans,i+1+maxpos+1);
        }
        return ans;
    }
};