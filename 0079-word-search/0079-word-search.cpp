class Solution {
public:
    vector<pair<int,int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(int i,int j,int ptr,string &word,vector<vector<char>>&board) {
        if (ptr == word.size()) return true;
        if (i<0 || i>= board.size() || j < 0 || j >= board[0].size() || 
            board[i][j] == '.' || board[i][j] != word[ptr]) return false;
        
        char ch = board[i][j];
        board[i][j] = '.';
        bool anse=false;
        for(auto &d:dirs){
            anse|=dfs(i+d.first,j+d.second,ptr+1,word,board);
        }
        board[i][j] = ch;
        return anse;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(i, j,0, word,board)) return true;
            }
        }
        return false;
    }
};