class TrieNode{
    public:
    TrieNode*children[26];
    int idx;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        idx=-1;
    }
};
class Trie{
    public:
    TrieNode*root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string &str,int i,vector<int>&ws){
        TrieNode*itr=root;
        for(auto &x:str){
            int idx=x-'a';
            if(!itr->children[idx]){
                itr->children[idx]=new TrieNode();
            }
            itr=itr->children[idx];
            if(itr->idx==-1){
                itr->idx=i;
            }
            else if(ws[i]<ws[itr->idx]){
                itr->idx=i;
            }
            else if(ws[i]==ws[itr->idx]){
                itr->idx=min(itr->idx,i);
            }
        }
    }
    void find(string &str,vector<int>&ans,int i){
        TrieNode*itr=root;
        for(auto &x:str){
            int iv=x-'a';
            if(!itr->children[iv])break;
            ans[i]=itr->children[iv]->idx;
            itr=itr->children[iv];
        }
    }
    
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        for(auto &x:wordsContainer)reverse(x.begin(),x.end());
   for(auto &x:wordsQuery)reverse(x.begin(),x.end());
        int ml=1e9,mli=-1;
        int n=wordsContainer.size(),q=wordsQuery.size();
        vector<int>ws(n);
        for(int i=0;i<n;i++){
            ws[i]=wordsContainer[i].size();
            if(ws[i]<ml){
                ml=ws[i];
                mli=i;
            }
        }
        Trie*t =new Trie();
        vector<int>ans(q,mli);
        for(int i=0;i<n;i++){
            t->insert(wordsContainer[i],i,ws);
        }
        for(int i=0;i<q;i++){
            t->find(wordsQuery[i],ans,i);
        }
        return ans;
        
    }
};