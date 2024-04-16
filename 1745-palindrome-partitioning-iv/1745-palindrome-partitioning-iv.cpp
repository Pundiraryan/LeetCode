class Solution {
public:
    vector<vector<int>> preprocess_substr_palindrome(string &s){
        int n=s.length();
        vector<vector<int>>isp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            isp[i][i]=1;
            if(i+1<n && s[i]==s[i+1])isp[i][i+1]=1;
        }
        for(int len=3;len<n;len++)
        {
            for(int i=0;i<n;i++)
            {
                int j=i+len-1;
                if(i<n && j<n && i+1<n && j-1<n && isp[i+1][j-1]==1 && s[i]==s[j])
                {
                    isp[i][j]=1;
                    isp[j][i]=1;
                }
            }
        }
        return isp;
    }
    
    bool checkPartitioning(string s) {
        int n=s.length();
        vector<vector<int>>isp=preprocess_substr_palindrome(s);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int l1=0,r1=i-1;
                int l3=j+1,r3=n-1;
                if(r1>=0 && l3<=r3 && isp[l1][r1] && isp[i][j] && isp[l3][r3])return true;
            }
        }
        return false;
    }
};