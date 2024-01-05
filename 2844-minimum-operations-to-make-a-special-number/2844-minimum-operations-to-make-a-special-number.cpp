class Solution {
public:
    int minimumOperations(string num) {
        int  n=num.length();
        int ans=n;
        map<int,vector<int>>fre;
        for(int i=0;i<n;i++){
            fre[num[i]-'0'].push_back(i);                      
        }
        vector<int>v0=fre[0];
        vector<int>v2=fre[2];
        vector<int>v5=fre[5];
        vector<int>v7=fre[7];
        if(!v0.empty())ans=n-1;
        for(int i=0;i<v0.size();i++){
                for(int j=i+1;j<v0.size();j++){
                    ans=min(ans,n-v0[j]-1+v0[j]-v0[i]-1);
                }
        }
        for(int i=0;i<v5.size();i++){
            for(int j=0;j<v0.size();j++){
                if(v0[j]<=v5[i])continue;
                ans=min(ans,n-v0[j]-1+v0[j]-v5[i]-1);
            }
        }
        for(int i=0;i<v2.size();i++){
            for(int j=0;j<v5.size();j++){
                if(v5[j]<=v2[i])continue;
                ans=min(ans,n-v5[j]-1+v5[j]-v2[i]-1);
            }
        }
         for(int i=0;i<v7.size();i++){
            for(int j=0;j<v5.size();j++){
                if(v5[j]<=v7[i])continue;
                ans=min(ans,n-v5[j]-1+v5[j]-v7[i]-1);
            }
        }
        return ans;
    }
};