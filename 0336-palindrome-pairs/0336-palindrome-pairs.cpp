class Solution {
public:
    bool isp(int l,int r,string str){
        while(l<r){
            if(str[l]!=str[r])return false;
            l++;r--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>ans;
        int n=words.size();
        unordered_map<string,int>fre;
        int ptr=-1;
        for(auto &x:words){
            ++ptr;
            if(x=="")continue;
            string str=x;
            reverse(str.begin(),str.end());
            fre[str]=ptr;
        }
        for(int i=0;i<n;i++){
            if(words[i]==""){
                for(int j=0;j<n;j++){
                    if(i!=j && isp(0,words[j].size()-1,words[j])){
                        ans.push_back({i,j});
                        ans.push_back({j,i});
                    }
                }
            }
            for(int j=0;j<words[i].size();j++){
                if(isp(j,words[i].size()-1,words[i])){
                 string left=words[i].substr(0,j);
                    if(fre.find(left)!=fre.end() && fre[left]!=i){
                        ans.push_back({i,fre[left]});
                    }
                }
                if (isp(0,j-1,words[i])) {
					string right = words[i].substr(j);
					if (fre.find(right) != fre.end() && fre[right]!= i) {
						ans.push_back({fre[right],i});
					}
				}
          }
        }
        return ans;
    }
};