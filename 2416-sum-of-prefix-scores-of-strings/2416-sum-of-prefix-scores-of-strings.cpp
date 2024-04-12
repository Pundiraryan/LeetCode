class TrieNode{
    public:
    TrieNode*children[26];
    int cnt=0;
    TrieNode(){
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
class Trie{
    public:
    TrieNode*root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string str){
        TrieNode*itr=root;
        for(auto &x:str){
            if(!itr->children[x-'a']){
                itr->children[x-'a']=new TrieNode;
            }
            itr->children[x-'a']->cnt++;
            itr=itr->children[x-'a'];
        }
    }
    int cnt(string str){
        int res=0;
        TrieNode*itr=root;
        for(auto &x:str){
            res+=itr->children[x-'a']->cnt;
            itr=itr->children[x-'a'];
        }
        return res;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        vector<int>ans(n);
        Trie* t=new Trie();
        for(auto &x:words)t->insert(x);
        for(int i=0;i<n;i++){
            ans[i]=t->cnt(words[i]);
        }
        return ans;
    }
};