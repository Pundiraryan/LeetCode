class Solution {
public:
    string minWindow(string s, string t) {
         int n=s.size();
        int m=t.size();
        unordered_map<char,int>fre;
        for(auto &x:t)fre[x]++;
        int st=0,e=0,as=0,al=INT_MAX;
        int counter=t.size();
        while(e<n){
            if(fre[s[e]]>0)counter--;
            fre[s[e]]--;
            e++;
            while(counter==0){
                if(e-st <al){
                    al=e-st;
                    as=st;
                }
                fre[s[st]]++;
			    if (fre[s[st]] > 0)
				    counter++;
			    st++;
		    }
	    }
	    if (al != INT_MAX)return s.substr(as, al);
	    return "";
                
    }
};