class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string st=to_string(low);
        string end=to_string(high);
        for(int i=st.length();i<=end.length();i++){
            for(int j=1;j<=9;j++){
                string curr="";
                for(int k=j;k<min(10,j+i);k++){
                    curr+=to_string(k);
                }
                if(curr.length()!=i)continue;
                int num=stoi(curr);
                if(num>=low && num<=high)ans.push_back(num);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};